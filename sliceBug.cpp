#include<iostream>
using namespace std;
struct Base {
    virtual int id() const { return 1; } 
    virtual ~Base() = default; 
};

struct Derived : Base { 
    int id() const override { return 2; } 
};
int take(Base *b) { 
    return b->id(); 
}
int main(){
    
    Derived *d = new Derived;
    std::cout << take(d); // prints 1 -- why?
    
    // run time polymorphism works with pointers + virtual functions.
}
