#include "String.hpp"
#include <iostream>

int main()
{
	// Малявский Михаил ПМ 4гр. 8пг.
	// Вариант 8
	setlocale(LC_ALL, "Russian");
	mm::String s1("abc");
	mm::String s2("bcd");
	mm::String s[2];
	for (int i = 0; i < 2; i++)
		std::cin >> s[i];
	std::cout << s1 << " " << s2 << " " << s[0] << " " << s[1] << std::endl;
	std::cout << "--------------------------------------------------------------------1" << std::endl;
	std::cout << (s1 + s2) << std::endl;
	std::cout << "--------------------------------------------------------------------2" << std::endl;
	std::cout << s1[2] << std::endl;
	std::cout << "--------------------------------------------------------------------3" << std::endl;
	std::cout << (s1 < s2) << std::endl;
	std::cout << "--------------------------------------------------------------------4" << std::endl;
	std::cout << s1.find('c') << std::endl;
	std::cout << "--------------------------------------------------------------------5" << std::endl;
	std::cout << s[0].length() << std::endl;
	std::cout << "--------------------------------------------------------------------6" << std::endl;
	std::cout << s1.c_str() << std::endl;
	std::cout << "--------------------------------------------------------------------7" << std::endl;
	try {
		std::cout << s1.at(4) << std::endl;
	}
	catch (const std::out_of_range& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "--------------------------------------------------------------------8" << std::endl;
	std::cout << ("ddd" + s1) << std::endl;
	return 0;
}