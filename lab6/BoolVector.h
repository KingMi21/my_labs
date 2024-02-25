#pragma once
#include <iostream>

namespace mm
{
    class reference 
    {
        char& m_byte;
        char m_mask;

    public:
        reference(char& byte, char mask) : m_byte(byte), m_mask(mask) {}
        reference& operator=(const reference& other)
        {
            m_byte = other.m_byte;
            m_mask = other.m_mask;
            return *this;
        }
        reference& operator=(bool value) 
        {
            if (value) 
            {
                m_byte |= m_mask;
            }
            else 
            {
                m_byte &= ~m_mask;
            }
            return *this;
        }
        operator bool() const 
        {
            return m_byte & m_mask;
        }
    };

    template <int N>
    class BoolVector
    {
        char* m_mas;
        int m_size;
        int m_capacity;
        void Copy(const BoolVector<N>& other);

    public:
        BoolVector();

        BoolVector(const BoolVector<N>& other);

        BoolVector<N>& operator=(const BoolVector<N>& other);

        ~BoolVector();

        void push_back(bool value);

        bool operator[](int index) const;

        reference operator[](int index);

        bool at(int index) const;

        reference at(int index);

        int size() const;

        void insert(int index, bool value);

        void erase(int index);

        void Print();
    };
}
#include "BoolVector.hpp"