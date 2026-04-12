#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int age = 0;
	std::cout << "Введите число :" << std::endl;
	std::cin >> age;

	std::cout << "Вы ввели :\n" << age  << std::endl;
}
