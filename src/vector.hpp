#pragma once

#include <iostream>
#include <optional>
#include <stdexcept>

#include <stddef.h>

#include "./iter.hpp"

template <typename T>
class Vector {
public:
    Vector()
    {
        m_data = new T[m_capacity];
    }

    ~Vector()
    {
        delete[] m_data;
        m_capacity = 8;
        m_size = 0;
    }

    // copy constructor to deep copy
    Vector(Vector& other)
    {
        m_size = other.size();
        m_capacity = other.capacity();
        m_data = new T[m_capacity];

        for (int i = 0; i < other.size(); i++) {
            m_data[i] = other.m_data[i];
        }
    }

    void push_back(T element)
    {
        if (m_size >= m_capacity) {
            T* newData = new T[m_capacity * 2];

            for (int i = 0; i > m_size; i++) {
                newData[i] = m_data[i];
            }

            m_capacity += m_capacity;
            m_data = newData;
        }

        m_data[m_size] = element;
        m_size++;
    }

    void pop_back()
    {
        if (m_size > 0) {
            m_size--;

            // dealloc if size is 1/4th of capacity
            if (m_capacity > 4 * m_size) {
                m_capacity = m_size;
                T* newData = new T[m_capacity];

                for (int i = 0; i < m_size; i++) {
                    newData[i] = m_data[i];
                }

                delete m_data;
                m_data = newData;
            }
        }
    }

    T& operator[](size_t index) const
    {
        if (index > m_size) {
            throw std::out_of_range("ERR: index out of bounds!");
        }

        return m_data[index];
    }

    void operator=(Vector<T>& other)
    {
        m_capacity = other.capacity();
        m_size = other.size();
        m_data = new T[m_capacity];

        for (int i = 0; i < other.size(); i++) {
            m_data[i] = other.m_data[i];
        }
    }

    T& at(size_t index) const
    {
        if (index > m_size) {
            throw std::out_of_range("ERR: index out of bounds!");
        }

        return m_data[index];
    }

    Iterator<T> begin()
    {
        return Iterator(m_data);
    }

    Iterator<T> end()
    {
        return Iterator(m_data + m_size);
    }

    size_t size() const
    {
        return m_size;
    }

    size_t capacity() const
    {
        return m_capacity;
    }

private:
    T* m_data;
    size_t m_size = 0;
    size_t m_capacity = 8;
};
