#include "Matrix.h"

namespace mm
{
	template<typename T, int N, int M>
	void Matrix<T, N, M>::Copy(const Matrix<T, N, M>& other)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				m_matrix[i][j] = other.m_matrix[i][j];
	}

	template<typename T, int N, int M>
	Matrix<T, N, M>::Matrix()
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				m_matrix[i][j] = 0;
		std::cout << "<Сработал конструктор>" << std::endl;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M>::Matrix(const Matrix& other)
	{
		Copy(other);
		std::cout << "<Сработал конструктор копирования>" << std::endl;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M>& Matrix<T, N, M>::operator=(const Matrix& other)
	{
		if (&other != this)
		{
			Copy(other);
		}
		std::cout << "<Сработал оператор присваивания копированием>" << std::endl;
		return *this;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M>::~Matrix()
	{
		std::cout << "<Сработал деструктор>" << std::endl;
	}

	template<typename T, int N, int M>
	void Matrix<T, N, M>::SetRow(int n)
	{
		if (n > 0 && n <= N)
		{
			std::cout << "Введите " << n << " строку из " << M << " элементов: ";
			for (int j = 0; j < M; j++)
				std::cin >> m_matrix[n - 1][j];
		}
		else
		{
			std::cout << "Error: Нет такой строки" << std::endl;
		}
	}

	template<typename T, int N, int M>
	void Matrix<T, N, M>::SetCol(int m)
	{
		if (m > 0 && m <= M)
		{
			std::cout << "Введите " << m << " столбец из " << N << " элементов: ";
			for (int i = 0; i < N; i++)
				std::cin >> m_matrix[i][m - 1];
		}
		else
		{
			std::cout << "Error: Нет такого столбца" << std::endl;
		}
	}

	template<typename T, int N, int M>
	std::istream& operator>>(std::istream& in, Matrix<T, N, M>& other)
	{
		for (int i = 0; i < N; i++)
		{
			std::cout << "Введите " << i + 1 << " строку из " << M << " элементов: ";
			for (int j = 0; j < M; j++)
				std::cin >> other.m_matrix[i][j];
		}
		return in;
	}

	template<typename T, int N, int M>
	std::ostream& operator<<(std::ostream& out, const Matrix<T, N, M>& other)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
				std::cout << other.m_matrix[i][j] << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
		return out;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M>& Matrix<T, N, M>::operator+=(const Matrix<T, N, M>& other)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				m_matrix[i][j] += other.m_matrix[i][j];
		std::cout << "Сработал оператор +=" << std::endl;
		return *this;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M> Matrix<T, N, M>::operator+(const Matrix<T, N, M>& other)
	{
		Matrix<T, N, M> tmp = *this;
		tmp += other;
		std::cout << "Сработал оператор +" << std::endl;
		return tmp;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M>& Matrix<T, N, M>::operator++()
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				m_matrix[i][j] += 1;
		return *this;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M> Matrix<T, N, M>::operator++(int)
	{
		Matrix<T, N, M> tmp = *this;
		++(*this);
		return tmp;
	}

	template<typename T, int N, int M>
	template<int L>
	Matrix<T, N, L> Matrix<T, N, M>::operator*(const Matrix<T, M, L>& other)
	{
		Matrix<T, N, L> tmp;
		T sum;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < L; j++)
			{
				sum = 0;
				for (int k = 0; k < M; k++)
				{
					sum += m_matrix[i][k] * other.m_matrix[k][j];
				}
				tmp.m_matrix[i][j] = sum;
			}
		}
		std::cout << "Сработал оператор *" << std::endl;
		return tmp;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M>& Matrix<T, N, M>::operator*=(const Matrix<T, M, M>& other)
	{
	    *this = (*this * other);
		std::cout << "Сработал оператор *=" << std::endl;
		return *this;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M>& Matrix<T, N, M>::operator*=(T n)
	{
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				m_matrix[i][j] *= n;
		std::cout << "Сработал оператор *= на число" << std::endl;
		return *this;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M> Matrix<T, N, M>::operator*(T n)
	{
		Matrix<T, N, M> tmp = *this;
		tmp *= n;
		std::cout << "Сработал оператор * на число" << std::endl;
		return tmp;
	}

	template<typename T, int N, int M>
	Matrix<T, N, M> operator*(T n, const Matrix<T, N, M>& other)
	{
		Matrix<T, N, M> tmp = other;
		tmp *= n;
		std::cout << "Сработал оператор * на число" << std::endl;
		return tmp;
	}

	template<typename T, int N, int M>
	T* Matrix<T, N, M>::operator[](int i)
	{
		return m_matrix[i];
	}

	template<typename T, int N, int M>
	T Matrix<T, N, M>::Det()
	{
		if (N == M)
		{
			if (N == 1)
			{
				return m_matrix[0][0];
			}
			else if (N == 2)
			{
				return m_matrix[0][0] * m_matrix[1][1] - m_matrix[0][1] * m_matrix[1][0];
			}
			else if (N == 3)
			{
				T det = 0;
				det += m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2];
				det += m_matrix[0][2] * m_matrix[1][0] * m_matrix[2][1];
				det += m_matrix[0][1] * m_matrix[1][2] * m_matrix[2][0];

				det -= m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0];
				det -= m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2];
				det -= m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1];
				return det;
			}
			else
			{
				std::cout << "Error: Матрица с недопустимым размером" << std::endl;
				return -1;
			}
		}
		else
		{
			std::cout << "Error: Матрица с недопустимым размером" << std::endl;
			return -1;
		}
	}
}