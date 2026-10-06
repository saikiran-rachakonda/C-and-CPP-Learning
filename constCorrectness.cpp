#include<vector>
#include<iostream>
using namespace std;
class Table {
 vector<int> m_v;
 mutable bool m_cached = false;
 mutable int sum = 0 ;
public:
    Table(int s) {
        for(int i=0;i<s;i++){
            m_v.push_back(i);
        }
    }
 // usable as t.at(0) = 5; AND const Table& ct; ct.at(0);
    int& at(int x){
        return m_v.at(x);
    }
    const int& at(int x) const{
        return m_v.at(x);
    }
 // int cached_sum() const; -- computes once, remembers
    int cached_sum() const{
        if(!m_cached){
            for(int value:m_v){
                sum += value;
            }
            m_cached = true;
            return 0;
        } else {
            return sum;
        }
    }
    
};
int main()
{
    Table t(5);

    // Non-const at()
    t.at(0) = 10;

    std::cout << t.at(0) << '\n';

    // Const Table
    const Table& ct = t;

    std::cout << ct.at(0) << '\n';

    // First call → computes
    std::cout << ct.cached_sum() << '\n';

    // Second call → returns cached result
    std::cout << ct.cached_sum() << '\n';

    return 0;
}
