#pragma once

namespace mm
{
	// Изменение размера массива
	void ResizeMas(int*& mas, int size, int new_size);

	// Изменение размера матрицы
	void ResizeMatrix(int**& matrix, int n, int new_n, int m);

	class Matrix
	{
		int m_n; // Количество строк
		int m_m; // Количество столбцов
		int** m_matrix; // Матрица
		void Create(int n, int m); // Создание матрицы
		void Delete(); // Удаление матрицы
		void Copy(const Matrix& other); // Копирование матрицы

	public:
		// Конструктор по умолчанию
		Matrix();

		// Конструктор
		Matrix(int n, int m);

		// Конструктор копирования
		Matrix(const Matrix& other);

		// Оператор присваивания копированием
		Matrix& operator=(const Matrix& other);

		// Деструктор
		~Matrix();

		// Задание матрицы
		void Setup(int n, int m);

		// Задание элементов матрицы
		void SetEl();

		// Задание элементов строки
		void SetRow(int n);

		// Задание элементов столбца
		void SetCol(int m);

		// Сеттеры
		void SetN(int n);
		void SetM(int m);

		// Геттеры
		int GetN();
		int GetM();

		// Вывод матрицы
		void Print();
	};
}