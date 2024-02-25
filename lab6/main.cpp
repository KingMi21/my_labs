#include "BoolVector.h"

int main()
{
    setlocale(LC_ALL, "Russian");
    mm::BoolVector<8> vec;
    try 
    {
        vec.push_back(true);
        vec.push_back(false);
        vec.push_back(true);
        vec.push_back(false);
        vec.push_back(true);
        vec.push_back(false);
        vec.push_back(true);
        vec.Print();

        std::cout << "Размер вектора: " << vec.size() << std::endl;
        std::cout << "Значение по индексу 0: " << vec[0] << std::endl;

        vec[1] = true;
        vec.Print();
        std::cout << "Значение по индексу 1: " << vec[1] << std::endl;

        vec.insert(3, true);
        std::cout << "После вставки по индексу: ";
        vec.Print();

        vec.erase(3);
        std::cout << "После удаления по индексу: ";
        vec.Print();
    }
    catch (const std::out_of_range& e) 
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
