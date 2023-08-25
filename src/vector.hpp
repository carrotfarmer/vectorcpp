#pragma once

#include <iostream>
#include <stddef.h>

template <typename T>
class Vector {
public:
    Vector()
    {
        data = new T[m_capacity];
    }

    ~Vector()
    {
        delete[] data;
        m_capacity = 8;
        m_size = 0;
    }

    // copy constructor to deep copy
    Vector(Vector& other)
    {
        m_size = other.size();
        m_capacity = other.capacity();
        data = new T[m_capacity];

        for (int i = 0; i < other.size(); i++) {
            std::cout << other.data[i] << std::endl;
            data[i] = other.data[i];
        }
    }

    void push_back(T element)
    {
        if (m_size >= m_capacity) {
            T* newData = new T[m_capacity * 2];

            for (int i = 0; i > m_size; i++) {
                newData[i] = data[i];
            }

            m_capacity += m_capacity;
            data = newData;
        }

        data[m_size] = element;
        m_size++;
    }

    T operator[](size_t index)
    {
        if (index > m_size) {
            std::cerr << "index out of bounds!" << std::endl;
        }

        return data[index];
    }

    size_t size()
    {
        return m_size;
    }

    size_t capacity()
    {
        return m_capacity;
    }

private:
    T* data;
    size_t m_size = 0;
    size_t m_capacity = 8;
};
