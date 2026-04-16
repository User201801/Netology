#include <iostream>
    std::cin >> text // Чтение строки до первого разделителя (входит не только #10, но и #32). 
                     // Рекомендуется использовать чтение всей строки std::getline(std::cin, text).
	std::cin.ignore(count, char); // Пропускает count символов, если не встречается символ char.
    // Очищаем буфер полностью (более надежный вариант)
    // Есть проблема с макросами из <windows.h>, для отключения использовать:
    // 1. #define NOMINMAX до подключения <windows.h>.
    // 2. #undef max, #undef min после подключения <windows.h>.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    std::cout << text << std::endl;  // Вывод данных.
    std::cin.peek(); // чтение данных по 1 символу.
#include <windows.h>
  	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#include <clocale>
    char* new_locale = setlocale(LC_ALL, "Russian"); // проверять на nullptr.

#include <string>
    std::getline(std::cin, text) // Читает введенную строку.

#include <format>
    std::cout << std::format("{},{},{}", max, middle, min) << std::endl;

1. явное приведение типа
● круглые скобки
● static_cast
● dynamic_cast
● const_cast
● reinterpret_cast

