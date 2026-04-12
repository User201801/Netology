#include <iostream>
#include <string>
#include <limits>  // для std::numeric_limits
#define NOMINMAX   // отключаем макросы min и max.
#include <windows.h>


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Чтение слова. 
	std::string word;
	std::cout << "Введите слово :" << std::endl;
	std::cin >> word;  
	std::cout << "Вы ввели :\n" << word << std::endl;

	// Убираем лишний ввод. Чтобы ввести текст. Частный случай. 
	// Пропускает count символов, если не встречается символ char.
	// std::cin.ignore(count, char);

    // Очищаем буфер полностью (более надежный вариант)  
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Чтение текста
	std::string text;
	std::cout << "Введите текст :" << std::endl;
	std::getline(std::cin, text);

	std::cout << "Вы ввели :\n" << text << std::endl;
}