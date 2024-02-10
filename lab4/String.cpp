#include "String.hpp"

namespace mm
{
	void ResizeMas(char*& mas, int size, int new_size)
	{
		char* new_mas = new char[new_size];
		size = size < new_size ? size : new_size;

		for (int i = 0; i < size; i++)
			new_mas[i] = mas[i];

		delete[] mas;

		mas = new_mas;
	}

	void String::Copy(const String& other)
	{
		m_size = other.m_size;
		m_str = new char[m_size];
		std::copy(other.m_str, other.m_str + m_size, m_str);
	}

	String::String()
	{
		m_size = 1;
		m_str = new char[m_size];
		m_str[0] = '\0';
	}

	String::String(const char* s)
	{
		m_size = (int)strlen(s) + 1;
		m_str = new char[m_size];
		std::copy(s, s + m_size, m_str);
	}

	String::String(const char ch)
	{
		m_size = 2;
		m_str = new char[m_size];
		m_str[0] = ch;
		m_str[1] = '\0';
	}

	String::String(const String& other)
	{
		Copy(other);
	}

	String& String::operator=(const String& other)
	{
		delete[] m_str;
		Copy(other);
		return *this;
	}

	String::~String()
	{
		delete[] m_str;
	}

	String& String::operator+=(const String& other)
	{
		int new_size = m_size + other.m_size - 1;
		ResizeMas(m_str, m_size, new_size);
		m_size = new_size;
		strcat_s(m_str, m_size, other.m_str);
		return *this;
	}

	String String::operator+(const String& other)
	{
		String tmp(m_str);
		tmp += other;
		return tmp;
	}

	const char& String::operator[](int i) const
	{
		return m_str[i];
	}

	char& String::operator[](int i)
	{
		return m_str[i];
	}

	bool String::operator==(const String& other)
	{
		return (strcmp(m_str, other.m_str) == 0);
	}

	bool String::operator!=(const String& other)
	{
		return (strcmp(m_str, other.m_str) != 0);
	}

	bool String::operator>(const String& other)
	{
		return (strcmp(m_str, other.m_str) > 0);
	}

	bool String::operator<(const String& other)
	{
		return (strcmp(m_str, other.m_str) < 0);
	}

	int String::find(char ch)
	{
		for (int i = 0; i < m_size; i++)
		{
			if (m_str[i] == ch)
			{
				return i;
			}
		}
		return -1;
	}

	int String::length()
	{
		return m_size - 1;
	}

	char* String::c_str()
	{
		return m_str;
	}

	const char& String::at(int i) const
	{
		if (i >= 0 && i < m_size)
		{
			return m_str[i];
		}
		throw std::out_of_range("Error: ������������ ������");
	}

	char& String::at(int i)
	{
		if (i >= 0 && i < m_size)
		{
			return m_str[i];
		}
		throw std::out_of_range("Error: ������������ ������");
	}

	std::istream& operator>>(std::istream& in, String& other)
	{
		char* tmp = new char[1000];
		std::cin >> tmp;
		int new_size = (int)strlen(tmp) + 1;
		ResizeMas(other.m_str, other.m_size, new_size);
		std::copy(tmp, tmp + new_size, other.m_str);
		other.m_size = new_size;
		return in;
	}

	std::ostream& operator<<(std::ostream& out, const String& other)
	{
		out << other.m_str;
		return out;
	}

	String operator+(const char* s, const String& other)
	{
		String tmp(s);
		tmp += other;
		return tmp;
	}

	String operator+(char ch, const String& other)
	{
		String tmp(ch);
		tmp += other;
		return tmp;
	}
}