#include <iostream>
#include <utility>
using namespace std;

class Test {
public:
    int value;

    Test(int v) : value(v) {
        cout << "Test constructed: " << value << endl;
    }

    ~Test() {
        cout << "Test destroyed: " << value << endl;
    }

    void print() {
        cout << "print Value = " << value << endl;
    }
};

template <typename T>
class UniquePtr {
private:
    T* ptr_ = nullptr;

public:
    explicit UniquePtr(T* ptr = nullptr)
        : ptr_(ptr)
    {
        cout<<"parametarised constructor" << endl;
    }

    ~UniquePtr()
    {
        cout<<"destructor called." << endl;
        delete ptr_;
    }

    // No Copying 
    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    // Move constructor
    UniquePtr(UniquePtr&& other) noexcept
        : ptr_(other.ptr_)
    {
        cout<<"move constructor called." << endl;
        other.ptr_ = nullptr;
    }

    // Move assignment
    UniquePtr& operator=(UniquePtr&& other) noexcept
    {
        cout << "move assignment constructor called." << endl;
        if (this != &other) {
            delete ptr_;

            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }

        return *this;
    }

    T& operator*() const
    {
        cout<<"operator* called." << endl;
        return *ptr_;
    }

    T* operator->() const
    {
        cout<<"operator-> called." << endl;
        return ptr_;
    }

    T* get() const
    {
        cout<<"get() is called." << endl;
        return ptr_;
    }

    T* release()
    {
        cout<<"release() is called." << endl;
        T* temp = ptr_;
        ptr_ = nullptr;
        return temp;
    }

    void reset(T* ptr = nullptr)
    {
        cout<<"reset() is called." << endl;
        if (ptr_ != ptr) {
            delete ptr_;
            ptr_ = ptr;
        }
    }

    explicit operator bool() const
    {
        cout<<"bool operator is called." << endl;
        return ptr_ != nullptr;
    }
};

int main()
{
    cout << "\n--- 1. Constructor ---\n";

    UniquePtr<Test> p1(new Test(10));

    cout << "\n--- 2. operator* ---\n";

    cout << "Value using *p1 = "
         << (*p1).value << endl;
    //(*p1).print();
    
    cout << "\n--- 3. operator-> ---\n";

    p1->print();

    cout << "\n--- 4. get() ---\n";

    cout << "Raw pointer = "
         << p1.get() << endl;
    
    cout << "\n--- 5. bool operator ---\n";

    if (p1) {
        cout << "p1 owns an object\n";
    }
    
    cout << "\n--- 6. Move constructor ---\n";

    UniquePtr<Test> p2(std::move(p1));

    cout << "p1 = "
         << p1.get() << endl;

    cout << "p2 = "
         << p2.get() << endl;

    if (!p1) {
        cout << "p1 is empty after move\n";
    }

    cout << "p2 value = "
         << p2->value << endl;

    cout << "\n--- 7. Move assignment ---\n";

    UniquePtr<Test> p3(new Test(30));

    cout << "Before move assignment:\n";
    cout << "p2 value = " << p2->value << endl;
    cout << "p3 value = " << p3->value << endl;

    p3 = std::move(p2);

    cout << "After move assignment:\n";

    if (!p2) {
        cout << "p2 is empty\n";
    }

    cout << "p3 value = "
         << p3->value << endl;
    
    cout << "\n--- 8. release() ---\n";

    Test* raw = p3.release();

    if (!p3) {
        cout << "p3 is empty after release\n";
    }

    cout << "Raw object value = "
         << raw->value << endl;

    // release() does NOT delete the object.
    // We must delete it manually.
    delete raw;
    
    cout << "\n--- 9. reset() ---\n";

    UniquePtr<Test> p4(new Test(40));

    cout << "Before reset: "
         << p4->value << endl;

    p4.reset(new Test(50));

    cout << "After reset: "
         << p4->value << endl;

    cout << "\n--- 10. reset() to nullptr ---\n";

    p4.reset();

    if (!p4) {
        cout << "p4 is empty after reset()\n";
    }

    cout << "\n--- 11. Automatic destruction ---\n";

    {
        UniquePtr<Test> p5(new Test(100));

        cout << "Inside scope: "
             << p5->value << endl;
    }

    cout << "Outside scope\n";

    return 0;
}
