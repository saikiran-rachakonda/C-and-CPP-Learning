#include <cstdint>

class Buffer {
    std::size_t m_n = 0;
    uint8_t* m_p = nullptr;

public:
    explicit Buffer(std::size_t n)
        : m_n(n),
          m_p(n ? new uint8_t[n] : nullptr)
    {
    }
    ~Buffer()
    {
        delete[] m_p;
    }

    Buffer(const Buffer& other)
        : m_n(other.m_n),
          m_p(other.m_n ? new uint8_t[other.m_n] : nullptr)
    {
        if (m_p) {
            for (std::size_t i = 0; i < m_n; ++i) {
            m_p[i] = other.m_p[i];
            }
        }
    }

    Buffer& operator=(const Buffer& other)
    {
        if (this != &other) {
            uint8_t* new_p = other.m_n ? new uint8_t[other.m_n] : nullptr;

            if (new_p) {
                for (std::size_t i = 0; i < m_n; ++i) {
                    new_p[i] = other.m_p[i];
                }
            }

            delete[] m_p;

            m_p = new_p;
            m_n = other.m_n;
        }

        return *this;
    }

    Buffer(Buffer&& other) noexcept
        : m_n(other.m_n),
          m_p(other.m_p)
    {
        other.m_n = 0;
        other.m_p = nullptr;
    }

    Buffer& operator=(Buffer&& other) noexcept
    {
        if (this != &other) {
            delete[] m_p;

            m_n = other.m_n;
            m_p = other.m_p;

            other.m_n = 0;
            other.m_p = nullptr;
        }

        return *this;
    }
};
