#include "BigInt.hpp"

int main()
{
	// Малявский Михаил ПМ 4гр. 8пг.
	// Вариант 8
	setlocale(LC_ALL, "Russian");
	mm::BigInt s1("100");
	mm::BigInt s2("0");
	/*mm::BigInt s[2];
	for (int i = 0; i < 2; i++)
		std::cin >> s[i];
	std::cout << s1 << " " << s2 << " " << s[0] << " " << s[1] << std::endl;*/
	std::cout << (s1 * s2) << std::endl;
	return 0;
}