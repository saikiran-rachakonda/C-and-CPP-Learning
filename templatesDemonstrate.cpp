#include<cstdint>
#include<iostream>
using namespace std;
template <typename T, size_t Capacity>
class RingBuffer {
private:
    T buffer[Capacity];

    std::size_t head = 0;
    std::size_t tail = 0;
    std::size_t count = 0;

public:
    RingBuffer() {
        if (Capacity == 0 || (Capacity & (Capacity - 1)) != 0) {
            cout<<"Capacity should be power of 2."<< endl;
        }
    }

    bool push(const T& value) {
        if (full())
            return false;

        buffer[tail] = value;

        tail = (tail + 1) % Capacity;
        count++;

        return true;
    }

    bool pop(T& value) {
        if (empty())
            return false;

        value = buffer[head];

        head = (head + 1) % Capacity;
        count--;

        return true;
    }

    bool empty() const {
        return count == 0;
    }

    bool full() const {
        return count == Capacity;
    }

    size_t size() const {
        return count;
    }

    static size_t capacity() {
        return Capacity;
    }
};
int main(){
    RingBuffer<int,16> some;
    return 0;
}
