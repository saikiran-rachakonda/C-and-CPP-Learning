#include<cstdint>
#include<iostream>
using namespace std;
class regr {
    uint32_t reg;
    
    public :
        uint32_t read(){
            return reg;
        }
        void write(uint32_t val){
            reg = val;
        }
        regr() : reg(0) {
            cout<<"default constructor called" << endl;
        }
        regr(uint32_t val) : reg( val ){
            cout<<"parametarised constructor called" << endl;
        }
        regr& operator= (regr& s){
            write(s.reg);
            return *this;
        }
        regr& operator|= (uint32_t val){
            cout<<"|= is called."<<endl;
            write(read() | val );
            return *this;
        }
        operator uint32_t(){
            cout<<"uint32_t is called."<<endl;
            return read();
        }
        bool test(int x){
            return (read() & (1 << x) ) != 0 ;
        }
};
int main(){
    regr r(0);
    regr s(1);
    s = r;
    s |= 0x0F;
    uint32_t x = r;
    return 0;
}
