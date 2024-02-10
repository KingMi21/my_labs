#pragma once
#include <iostream>

namespace mm
{
	// ��������� ������� �������
	void ResizeMas(char*& mas, int size, int new_size);

	class String
	{
		char* m_str; // ������
		int m_size; // ����� ������
		void Copy(const String& other); // ����������� �����

	public:
		// ����������� �� ���������
		String();

		// ������������
		String(const char* s);
		String(const char ch);

		// ����������� �����������
		String(const String& other);

		// �������� ������������ ������������
		String& operator=(const String& other);

		// ����������
		~String();

		// ��������� +=, +
		String& operator+=(const String& other);
		String operator+(const String& other);
		friend String operator+(char* s, const String& other);
		friend String operator+(char ch, const String& other);

		// �������� []
		const char& operator[](int i) const;
		char& operator[](int i);

		// ��������� ==, !=, >, <
		bool operator==(const String& other);
		bool operator!=(const String& other);
		bool operator>(const String& other);
		bool operator<(const String& other);

		friend std::istream& operator>>(std::istream& in, String& other);
		friend std::ostream& operator<<(std::ostream& out, const String& other);

		// ����� ������� ��������� ������� � �������� ������ �����
		int find(char ch);

		// ����� ������
		int length();

		// ������ char
		char* c_str();

		// ������ � ��������� ��������
		const char& at(int i) const;
		char& at(int i);
	};
	// �������� +
	String operator+(const char* s, const String& other);
	String operator+(char ch, const String& other);

	// ��������� ����� � ������ � �����
	std::istream& operator>>(std::istream& in, String& other);
	std::ostream& operator<<(std::ostream& out, const String& other);
}