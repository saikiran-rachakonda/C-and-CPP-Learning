#include<iostream>
using namespace std;
class Latch { public: 
    
    void acquire(){
        cout << "latch acquired." << endl;
    } 
    
    void release(){
        cout << "latch released." << endl;
    }
    
};
class ScopedLatch { 
    private :
    Latch* latch_;
    
    public :
    ScopedLatch(Latch& latch) : latch_(&latch){
        latch_->acquire();
    }
    ~ScopedLatch(){
        if(latch_!=nullptr) latch_->release();
    }
    ScopedLatch(ScopedLatch&& other)
        : latch_(other.latch_)
    {
        cout<<"move constructor" << endl;
        other.latch_ = nullptr;
    }

    ScopedLatch& operator=(ScopedLatch&& other)
    {
        cout<<"move assignment constructor." << endl;
        if (this != &other) {
            if (latch_ != nullptr)
                latch_->release();

            latch_ = other.latch_;
            other.latch_ = nullptr;
        }

        return *this;
    }
};
int main(){
    Latch x;
    Latch y;
    cout << "x latch scope"<<endl;
    ScopedLatch b(x);
    cout << "move b latch to new c scoped latch." << endl;
    ScopedLatch c(move(b));
    cout<<" y latch scope" << endl;
    ScopedLatch a(y);
    cout << "move b latch to existing a scoped latch." << endl;
    a = move(c);
}
