#pragma once
#include <iostream>

namespace mm
{
	template<typename T, int N, int M>
	class Matrix
	{
		T m_matrix[N][M]; // �������

		// ����������� �������
		void Copy(const Matrix& other);

	public:
		// �����������
		Matrix();

		// ����������� �����������
		Matrix(const Matrix& other);

		// �������� ������������ ������������
		Matrix& operator=(const Matrix& other);

		// ����������
		~Matrix();

		// ������� ��������� ������
		void SetRow(int n);

		// ������� ��������� �������
		void SetCol(int m);

		// ��������� ����� � ������
		template<typename T, int N, int M>
		friend std::istream& operator>>(std::istream& in, Matrix<T, N, M>& other);

		template<typename T, int N, int M>
		friend std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& other);

		Matrix& operator+=(const Matrix& other);

		Matrix operator+(const Matrix& other);

		template<int L>
		Matrix<T, N, L> operator*(const Matrix<T, M, L>& other);

		Matrix& operator*=(const Matrix<T, M, M>& other);

		Matrix& operator*=(T n);

		Matrix operator*(T n);

		Matrix& operator++();

		Matrix operator++(int);

		template<typename T, int N, int M>
		friend Matrix operator*(T n, const Matrix& other);

		T* operator[](int i);

		T Det();
	};
}
#include "Matrix.hpp"