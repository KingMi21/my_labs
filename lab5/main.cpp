#include "Matrix.h"

template <typename T, int N, int M>
void Test(mm::Matrix<T, N, M> mat)
{
	mat.Print();
	std::cout << "Test function" << std::endl;
}

int main()
{
	// Малявский Михаил ПМ 4гр. 8пг.
	// Вариант 8
	setlocale(LC_ALL, "Russian");
	mm::Matrix<int,3, 3> mat1;
	std::cin >> mat1;

	std::cout << (mat1.Det());
	return 0;
}