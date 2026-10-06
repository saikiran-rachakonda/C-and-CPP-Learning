#include<iostream>
#include<cstdint>
#include<vector>
#include<memory>
using namespace std;

class Peripheral {
public:
 virtual uint32_t read(uint32_t off) const = 0;
 virtual void write(uint32_t off, uint32_t v) = 0;
 virtual ~Peripheral() = default;
};

class PeripheralOne : public Peripheral{
    uint32_t dataOne;
    public :
    uint32_t read(uint32_t off) const {
        if(off==0x00) return dataOne;
        return 0;
    }
    void write(uint32_t off, uint32_t v){
        if(off==0x00) dataOne = v;
    }
};

class PeripheralTwo : public Peripheral{
    uint32_t dataTwo;
    public : 
    uint32_t read(uint32_t off) const {
        if(off==0x01) return dataTwo;    
        return 0;
    }
    void write(uint32_t off, uint32_t v){
        if(off==0x01) dataTwo = v;
    }
};

int main(){
     // One container holding different peripheral types
    vector<unique_ptr<Peripheral>> peripherals;

    peripherals.push_back(make_unique<PeripheralOne>());
    peripherals.push_back(make_unique<PeripheralTwo>());

    // Dispatch through base interface
    peripherals[0]->write(0x00, 100);

    cout << "PeripheralOne read: " << peripherals[0]->read(0x00) << endl;

    peripherals[1]->write(0x01, 65);

    cout << "PeripheralTwo read: " << peripherals[1]->read(0x00) << endl;

    return 0;
}
