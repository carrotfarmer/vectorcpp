#pragma once

#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <stdexcept>

#include "./iter.hpp"

template <typename T>
class Vector {
public:
    Vector()
    {
        m_data = new T[m_capacity];
    }

    Vector(std::initializer_list<T> list)
    {
        m_capacity = std::max(list.size(), size_t { 1 });
        m_data = new T[m_capacity];

        for (const T& elem : list) {
            push_back(elem);
        }
    }

    ~Vector()
    {
        delete[] m_data;
    }

    Vector(const Vector& other)
    {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        m_data = new T[m_capacity];

        for (size_t i = 0; i < m_size; ++i) {
            m_data[i] = other.m_data[i];
        }
    }

    Vector& operator=(const Vector& other)
    {
        if (this == &other) {
            return *this;
        }

        T* new_data = new T[other.m_capacity];
        for (size_t i = 0; i < other.m_size; ++i) {
            new_data[i] = other.m_data[i];
        }

        delete[] m_data;
        m_data = new_data;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        return *this;
    }

    void push_back(T element)
    {
        if (m_size >= m_capacity) {
            const size_t new_capacity = m_capacity == 0 ? 1 : m_capacity * 2;
            T* new_data = new T[new_capacity];

            for (size_t i = 0; i < m_size; ++i) {
                new_data[i] = m_data[i];
            }

            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }

        m_data[m_size] = element;
        ++m_size;
    }

    void pop_back()
    {
        if (m_size == 0) {
            return;
        }

        --m_size;
        if (m_capacity > 4 * m_size) {
            const size_t new_capacity = std::max(m_size, size_t { 1 });
            T* new_data = new T[new_capacity];

            for (size_t i = 0; i < m_size; ++i) {
                new_data[i] = m_data[i];
            }

            delete[] m_data;
            m_data = new_data;
            m_capacity = new_capacity;
        }
    }

    T& operator[](size_t index) const
    {
        if (index >= m_size) {
            throw std::out_of_range("ERR: index out of bounds!");
        }
        return m_data[index];
    }

    T& at(size_t index) const
    {
        if (index >= m_size) {
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

    [[nodiscard]] size_t size() const
    {
        return m_size;
    }

    [[nodiscard]] size_t capacity() const
    {
        return m_capacity;
    }

private:
    T* m_data;
    size_t m_size = 0;
    size_t m_capacity = 8;
};
