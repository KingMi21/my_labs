#include "Matrix.hpp"
#include <iostream>

namespace mm
{
	void ResizeMas(int*& mas, int size, int new_size)
	{
		int* new_mas = new int[new_size];
		size = size < new_size ? size : new_size;
		for (int i = 0; i < new_size; i++)
		{
			if (i < size)
				new_mas[i] = mas[i];
			else
				new_mas[i] = 0;
		}

		delete[] mas;

		mas = new_mas;
	}

	void ResizeMatrix(int**& matrix, int n, int new_n, int m)
	{
		int** new_matrix = new int*[new_n];
		n = n < new_n ? n : new_n;
		for (int i = 0; i < new_n; i++)
		{
			new_matrix[i] = new int[m];
			if (i < n)
			{
				for (int j = 0; j < m; j++)
					new_matrix[i][j] = matrix[i][j];
			}
			else
			{
				for (int j = 0; j < m; j++)
					new_matrix[i][j] = 0;
			}
		}
			

		for (int i = 0; i < n; i++)
		{
			delete[] matrix[i];
		}
		delete[] matrix;

		matrix = new_matrix;
	}

	void Matrix::Create(int n, int m)
	{
		m_matrix = new int* [n];
		for (int i = 0; i < n; i++)
		{
			m_matrix[i] = new int[m];
			for (int j = 0; j < m; j++)
				m_matrix[i][j] = 0;
		}
	}

	void Matrix::Delete()
	{
		for (int i = 0; i < m_n; i++)
		{
			delete[] m_matrix[i];
		}
		delete[] m_matrix;
	}

	void Matrix::Copy(const Matrix& other)
	{
		m_n = other.m_n;
		m_m = other.m_m;
		Create(m_n, m_m);
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
				m_matrix[i][j] = other.m_matrix[i][j];
	}

	void Matrix::SetN(int n)
	{
		if (n <= 0)
		{
			std::cout << "Error: Количество строк <= 0" << std::endl;
			return;
		}
		if (n > m_n)
		{
			ResizeMatrix(m_matrix, m_n, n, m_m);
		}
		else if (n < m_n)
		{
			for (int i = n; i < m_n; i++)
			{
				delete[] m_matrix[i];
			}
		}
		m_n = n;
	}
	void Matrix::SetM(int m)
	{
		if (m <= 0)
		{
			std::cout << "Error: Количество столбцов <= 0" << std::endl;
			return;
		}
		if (m > m_m)
		{
			for (int i = 0; i < m_n; i++)
			{
				ResizeMas(m_matrix[i], m_m, m);
			}	
		}
		m_m = m;
	}

	int Matrix::GetN()
	{
		return m_n;
	}
	int Matrix::GetM()
	{
		return m_m;
	}

	void Matrix::Setup(int n, int m)
	{
		SetN(n);
		SetM(m);
	}

	void Matrix::SetEl()
	{
		for (int i = 0; i < m_n; i++)
		{
			std::cout << "Введите " << i + 1 << " строку из " << m_m << " элементов: ";
			for (int j = 0; j < m_m; j++)
				std::cin >> m_matrix[i][j];
		}
	}

	void Matrix::SetRow(int n)
	{
		if (n > 0 && n <= m_n)
		{
			std::cout << "Введите " << n << " строку из " << m_m << " элементов: ";
			for (int j = 0; j < m_m; j++)
				std::cin >> m_matrix[n - 1][j];
		}
		else
		{
			std::cout << "Error: Нет такой строки" << std::endl;
		}
	}

	void Matrix::SetCol(int m)
	{
		if (m > 0 && m <= m_m)
		{
			std::cout << "Введите " << m << " столбец из " << m_n << " элементов: ";
			for (int i = 0; i < m_n; i++)
				std::cin >> m_matrix[i][m - 1];
		}
		else
		{
			std::cout << "Error: Нет такого столбца" << std::endl;
		}
	}

	Matrix::Matrix()
	{
		m_n = 1;
		m_m = 1;
		Create(m_n, m_m);
		std::cout << "<Сработал конструктор по умолчанию>" << std::endl;
	}

	Matrix::Matrix(int n, int m)
	{
		m_n = n;
		m_m = m;
		Create(m_n, m_m);
		std::cout << "<Сработал конструктор>" << std::endl;
	}

	Matrix::Matrix(const Matrix& other)
	{
		Copy(other);
		std::cout << "<Сработал конструктор копирования>" << std::endl;
	}

	Matrix& Matrix::operator=(const Matrix& other)
	{
		Delete();
		Copy(other);
		std::cout << "<Сработал оператор присваивания копированием>" << std::endl;
		return *this;
	}

	Matrix::~Matrix()
	{
		Delete();
		std::cout << "<Сработал деструктор>" << std::endl;
	}

	void Matrix::Print()
	{
		for (int i = 0; i < m_n; i++)
		{
			for (int j = 0; j < m_m; j++)
				std::cout << m_matrix[i][j] << " ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
}