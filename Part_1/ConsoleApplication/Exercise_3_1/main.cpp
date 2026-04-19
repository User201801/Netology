#include <iostream>
#include <format>
#include <windows.h>

//Напишите программу, которая выводит таблицу истинности для логических операторов || , &&, с применением логических выражений.
//
//Результат работы программы
//Оператор : ||
//true    true    true
//false   true    true
//true    false   true
//false   false   false
//
//Оператор : &&
//true    true    true
//false   true    false
//true    false   false
//false   false   false

bool OutValue(bool firstValue, bool secondValue) {
	std::cout << firstValue << " " << secondValue;
	return firstValue or secondValue;
}

int main()
{
	// Устанавливаем настройки консоли.
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Вывод логических значений делаю через std::format. std::boolalpha, решил не использовать.
	std::cout << "Оператор : ||" << std::endl;
	std::cout << std::format("{:5} || {:5} = {}", true, true, (true or true)) << std::endl;
	std::cout << std::format("{:5} || {:5} = {}", true, false, (true or false)) << std::endl;
	std::cout << std::format("{:5} || {:5} = {}", false, true, (false || true)) << std::endl;
	std::cout << std::format("{:5} || {:5} = {}", false, false, (false || false)) << std::endl;
	std::cout << std::endl;

	std::cout << "Оператор : &&" << std::endl;
	std::cout << std::format("{:5} && {:5} = {}", true, true, (true and true)) << std::endl;
	std::cout << std::format("{:5} && {:5} = {}", true, false, (true and false)) << std::endl;
	std::cout << std::format("{:5} && {:5} = {}", false, true, (false && true)) << std::endl;
	std::cout << std::format("{:5} && {:5} = {}", false, false, (false && false)) << std::endl;
}
