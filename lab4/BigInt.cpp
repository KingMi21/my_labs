#include "BigInt.hpp"

namespace mm
{
	void BigInt::EqualZeros(BigInt& a, BigInt& b)
	{
		while (a.m_size != b.m_size)
		{
			(a.m_size < b.m_size) ? (a = "0" + a.m_str) : (b = "0" + b.m_str);
		}
	}

	void BigInt::DelZeros(String& s)
	{
		String tmp;
		int i = 0;
		while ((s[i] == '0') && (i != s.length() - 1))
		{
			i++;
		}
		for (i; i < s.length(); i++)
		{
			tmp += s[i];
		}
		s = tmp;
	}

	BigInt::BigInt()
	{
		m_size = 1;
		m_str = "";
	}

	BigInt::BigInt(String s)
	{
		m_size = s.length() + 1;
		m_str = s;
	}

	BigInt& BigInt::operator+=(const BigInt& other)
	{
		String answer;
		BigInt a = m_str;
		BigInt b = other.m_str;
		EqualZeros(a, b);
		int sum;
		int r = 0;
		for (int i = a.m_size - 2; i > -1; i--)
		{
			sum = (a.m_str[i] - '0') + (b.m_str[i] - '0') + r;
			r = sum / 10;
			answer = ((sum % 10) + '0') + answer;
		}
		if (r != 0)
		{
			answer = (r + '0') + answer;
		}
		m_str = answer;
		return *this;
	}

	BigInt& BigInt::operator*=(const BigInt& other)
	{
		String number;
		BigInt a = m_str;
		BigInt b = other.m_str;
		BigInt result;
		BigInt tmp;
		if (m_size < other.m_size)
		{
			a = other.m_str;
			b = m_str;
		}
		int sum;
		int r = 0;
		for (int i = b.m_size - 2; i > -1; i--)
		{
			for (int j = a.m_size - 2; j > -1; j--)
			{
				sum = (a.m_str[j] - '0') * (b.m_str[i] - '0') + r;
				r = sum / 10;
				number = ((sum % 10) + '0') + number;
			}
			if (r != 0)
			{
				number = (r + '0') + number;
			}
			for (int n = i; n < b.m_size - 2; n++)
			{
				number += "0";
			}
			tmp = number;
			number = "";
			r = 0;
			result += tmp;
		}
		DelZeros(result.m_str);
		m_str = result.m_str;
		return *this;
	}

	BigInt BigInt::operator+(const BigInt& other)
	{
		BigInt tmp(m_str);
		tmp += other;
		return tmp;
	}

	BigInt BigInt::operator*(const BigInt& other)
	{
		BigInt tmp(m_str);
		tmp *= other;
		return tmp;
	}

	bool BigInt::operator==(const BigInt& other)
	{
		BigInt a = m_str;
		BigInt b = other.m_str;
		EqualZeros(a, b);
		return a.m_str == b.m_str;
	}

	bool BigInt::operator!=(const BigInt& other)
	{
		BigInt a = m_str;
		BigInt b = other.m_str;
		EqualZeros(a, b);
		return a.m_str != b.m_str;
	}

	bool BigInt::operator>(const BigInt& other)
	{
		BigInt a = m_str;
		BigInt b = other.m_str;
		EqualZeros(a, b);
		return a.m_str > b.m_str;
	}

	bool BigInt::operator<(const BigInt& other)
	{
		BigInt a = m_str;
		BigInt b = other.m_str;
		EqualZeros(a, b);
		return a.m_str < b.m_str;
	}

	std::istream& operator>>(std::istream& in, BigInt& other)
	{
		std::cin >> other.m_str;
		return in;
	}

	std::ostream& operator<<(std::ostream& out, const BigInt& other)
	{
		out << other.m_str;
		return out;
	}
}