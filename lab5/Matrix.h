#pragma once
#include <iostream>

namespace mm
{
	template<typename T, int N, int M>
	class Matrix
	{
		T m_matrix[N][M]; // Матрица

		// Копирование матрицы
		void Copy(const Matrix& other);

	public:
		// Конструктор
		Matrix();

		// Конструктор копирования
		Matrix(const Matrix& other);

		// Оператор присваивания копированием
		Matrix& operator=(const Matrix& other);

		// Деструктор
		~Matrix();

		// Задание элементов строки
		void SetRow(int n);

		// Задание элементов столбца
		void SetCol(int m);

		// Операторы ввода и вывода
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