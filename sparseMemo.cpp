#include<cstdint>
#include<iostream>
#include<unordered_map>
using namespace std;

class SparseMemory {
    unordered_map<uint64_t, uint32_t> sparsemem;
    public:
        uint32_t read32 (uint64_t addr) const{
            if(addr%4 != 0){
                cout<<"address must be aligned."<<endl;
                return 0;
            }
            auto it = sparsemem.find(addr);

            if (it == sparsemem.end()) {
                return 0;
            }

            return it->second;
        }
        void write32(uint64_t addr, uint32_t v){
            if(addr%4 != 0){
                cout<<"address must be aligned."<<endl;
                return ;
            }
            sparsemem[addr] = v ;
        }
        size_t pages_allocated() const{
            return sparsemem.size();
        }
};
int main(){
    SparseMemory s;
    s.write32(0x00,1);
    uint32_t v = s.read32(0x00);
    cout<<v;
    return 0;
}
