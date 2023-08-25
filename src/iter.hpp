#pragma once

template <typename T>

class Iterator {
public:
    Iterator(T* ptr)
        : m_ptr(ptr)
    {
    }

    Iterator& operator++()
    {
        m_ptr++;
        return *this;
    }

    bool operator!=(const Iterator& other)
    {
        return m_ptr != other.m_ptr;
    }

    T& operator*()
    {
        return *m_ptr;
    }

private:
    T* m_ptr;
};
