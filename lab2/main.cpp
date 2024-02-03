#include "Matrix.hpp"
#include <iostream>

void Test(mm::Matrix mat)
{
	mat.Print();
	std::cout << "Test function" << std::endl;
}

int main()
{
	// Малявский Михаил ПМ 4гр. 8пг.
	// Вариант 8
	setlocale(LC_ALL, "Russian");
	mm::Matrix mat1(2, 3);
	mm::Matrix mat2(4, 4);

	mm::Matrix mat[2];
	for (int i = 0; i < 2; i++)
	{
		int n, m;
		std::cout << "Введите значения N и M матрицы " << i + 3 << ": ";
		std::cin >> n >> m;
		mat[i].Setup(n, m);
	}
	std::cout << "-----------------------------------------------------1" << std::endl;
	mat1.Print();
	mat2.Print();
	mat[0].Print();
	mat[1].Print();

	std::cout << "-----------------------------------------------------2" << std::endl;
	mat1.SetEl();
	mat1.Print();

	std::cout << "-----------------------------------------------------3" << std::endl;
	mat1.SetN(5);
	mat1.Print();
	mat1.SetM(5);
	mat1.Print();

	std::cout << "-----------------------------------------------------4" << std::endl;
	mat1.SetRow(5);
	mat1.Print();
	mat1.SetCol(5);
	mat1.Print();

	std::cout << "-----------------------------------------------------5" << std::endl;
	Test(mat2);

	std::cout << "-----------------------------------------------------6" << std::endl;
	mat1 = mat2 = mat[0];
	mat1.Print();
	mat2.Print();
	mat[0].Print();

	return 0;
}