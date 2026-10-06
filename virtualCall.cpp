#include<iostream>
using namespace std;

struct B {
    
 const char* tag;
 
 B() {
     tag = describe();
 } ;
 
 virtual const char* describe() const { 
     return "base"; 
 }
 
 virtual ~B() = default;

};

struct D : public B { 
    D(){
        tag = describe();
    }
    const char* describe() const{ 
        return "derived"; 
    } 
};
int main(){
    B b;
    D d; // d.tag == "base" -- why?
    cout<<d.tag << endl ;
    cout<<b.tag << endl ;
    B *a = new B;
    cout<<a->tag<<endl;
    a = new D;
    cout<<a->tag<<endl;
}
