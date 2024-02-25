#include "BoolVector.h"

namespace mm
{
    template<int N>
    void BoolVector<N>::Copy(const BoolVector<N>& other)
    {
        for (int i = 0; i < N; i++)
            m_mas[i] = other.m_mas[i];
        m_size = other.m_size;
        m_capacity = other.m_capacity;
    }

    template<int N>
    BoolVector<N>::BoolVector()
    {
        m_size = 0;
        m_capacity = (N + 7) / 8;
        m_mas = new char[m_capacity];
        memset(m_mas, 0, m_capacity);
        std::cout << "<Сработал конструктор>" << std::endl;
    }

    template<int N>
    BoolVector<N>::BoolVector(const BoolVector<N>& other)
    {
        Copy();
        std::cout << "<Сработал конструктор копирования>" << std::endl;
    }

    template<int N>
    BoolVector<N>& BoolVector<N>::operator=(const BoolVector<N>& other)
    {
        if (&other != this)
        {
            Copy(other);
        }
        std::cout << "<Сработал оператор присваивания копированием>" << std::endl;
        return *this;
    }

    template<int N>
    BoolVector<N>::~BoolVector()
    {
        delete[] m_mas;
        std::cout << "<Сработал деструктор>" << std::endl;
    }

    template<int N>
    void BoolVector<N>::push_back(bool value)
    {
        if (m_size == N) 
        {
            throw std::out_of_range("Error: Вектор переполнен");
        }
        int i_byte = m_size / 8;
        int i_bit = m_size % 8;
        if (value) 
        {
            m_mas[i_byte] |= (1 << i_bit);
        }
        else 
        {
            m_mas[i_byte] &= ~(1 << i_bit);
        }
        m_size++;
    }

    template<int N>
    bool BoolVector<N>::operator[](int index) const
    {
        int i_byte = index / 8;
        int i_bit = index % 8;
        return (m_mas[i_byte] & (1 << i_bit)) != 0;
    }

    template<int N>
    reference BoolVector<N>::operator[](int index)
    {
        int i_byte = index / 8;
        int i_bit = index % 8;
        char& byte = m_mas[i_byte];
        char mask = 1 << i_bit;
        return reference(byte, mask);
    }

    template<int N>
    bool BoolVector<N>::at(int index) const
    {
        if (index < 0 || index >= m_size)
        {
            throw std::out_of_range("Error: Недопустимый индекс");
        }
        return (*this)[index];
    }

    template<int N>
    reference BoolVector<N>::at(int index)
    {
        if (index < 0 || index >= m_size)
        {
            throw std::out_of_range("Error: Недопустимый индекс");
        }
        return (*this)[index];
    }

    template<int N>
    int BoolVector<N>::size() const
    {
        return m_size;
    }

    template<int N>
    void BoolVector<N>::insert(int index, bool value)
    {
        if (index < 0 || index > m_size) 
        {
            throw std::out_of_range("Error: Недопустимый индекс");
        }
        if (m_size == N) 
        {
            throw std::out_of_range("Error: Вектор переполнен");
        }
        
        for (int i = m_size - 1; i >= index; i--)
        {
            (*this)[i + 1] = bool((*this)[i]);
        }
        (*this)[index] = value;
        m_size++;
    }

    template<int N>
    void BoolVector<N>::erase(int index)
    {
        if (index < 0 || index >= m_size) 
        {
            throw std::out_of_range("Error: Недопустимый индекс");
        }
        for (int i = index; i < m_size - 1; i++) 
        {
            (*this)[i] = bool((*this)[i + 1]);
        }
        m_size--;
    }

    template<int N>
    void BoolVector<N>::Print()
    {
        for (int i = 0; i < m_size; i++)
        {
            std::cout << (*this)[i];
        }
        std::cout << std::endl;
    }
}