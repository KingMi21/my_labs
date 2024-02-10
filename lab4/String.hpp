#pragma once
#include <iostream>

namespace mm
{
	// Изменение размера массива
	void ResizeMas(char*& mas, int size, int new_size);

	class String
	{
		char* m_str; // Строка
		int m_size; // Длина строки
		void Copy(const String& other); // Копирование строк

	public:
		// Конструктор по умолчанию
		String();

		// Конструкторы
		String(const char* s);
		String(const char ch);

		// Конструктор копирования
		String(const String& other);

		// Оператор присваивания копированием
		String& operator=(const String& other);

		// Деструктор
		~String();

		// Операторы +=, +
		String& operator+=(const String& other);
		String operator+(const String& other);
		friend String operator+(char* s, const String& other);
		friend String operator+(char ch, const String& other);

		// Оператор []
		const char& operator[](int i) const;
		char& operator[](int i);

		// Операторы ==, !=, >, <
		bool operator==(const String& other);
		bool operator!=(const String& other);
		bool operator>(const String& other);
		bool operator<(const String& other);

		friend std::istream& operator>>(std::istream& in, String& other);
		friend std::ostream& operator<<(std::ostream& out, const String& other);

		// Поиск первого вхождения символа в исходную строку слева
		int find(char ch);

		// Длина строки
		int length();

		// Массив char
		char* c_str();

		// Чтение и изменение элемента
		const char& at(int i) const;
		char& at(int i);
	};
	// Оператор +
	String operator+(const char* s, const String& other);
	String operator+(char ch, const String& other);

	// Операторы ввода и вывода в поток
	std::istream& operator>>(std::istream& in, String& other);
	std::ostream& operator<<(std::ostream& out, const String& other);
}