#pragma once
#include "String.hpp"

namespace mm
{
	class BigInt
	{
		String m_str; // Строка
		int m_size; // Длина строки
		void EqualZeros(BigInt& a, BigInt& b); // Уравнять незначащими нулями
		void DelZeros(String& s); // Удаление незначащих нулей

	public:
		// Конструктор по умолчанию
		BigInt();

		// Конструктор
		BigInt(String s);

		// Операторы +=, +
		BigInt& operator+=(const BigInt& other);
		BigInt operator+(const BigInt& other);

		// Операторы *=, *
		BigInt& operator*=(const BigInt& other);
		BigInt operator*(const BigInt& other);

		//// Операторы ==, !=, >, <
		bool operator==(const BigInt& other);
		bool operator!=(const BigInt& other);
		bool operator>(const BigInt& other);
		bool operator<(const BigInt& other);

		friend std::istream& operator>>(std::istream& in, BigInt& other);
		friend std::ostream& operator<<(std::ostream& out, const BigInt& other);
	};

	// Операторы ввода и вывода в поток
	std::istream& operator>>(std::istream& in, BigInt& other);
	std::ostream& operator<<(std::ostream& out, const BigInt& other);
}