#include <iostream>
// #include <clocale>  // Для первого варианта.
#include <windows.h>  // Для второго варианта.

int main()
{
    
    // вариант 1.
    //char* new_locale = setlocale(LC_ALL, "Russian");
    //if (new_locale == nullptr) {
    //    std::cout << "Не удалось установить локаль Russian" << std::endl;

    //    // Пробуем альтернативные варианты
    //    if (setlocale(LC_ALL, "ru_RU.UTF-8")) {
    //        std::cout << "Установлена локаль: ru_RU.UTF-8" << std::endl;
    //    }
    //    else if (setlocale(LC_ALL, "russian")) {
    //        std::cout << "Установлена локаль: russian" << std::endl;
    //    }
    //    else {
    //        std::cout << "Не найдена русская локаль" << std::endl;
    //    }
    //}
    //else {
    //    std::cout << "Установлена локаль: " << new_locale << std::endl;
    //}

    // вариант 2
    //SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Александр\n";
    std::cout << 39 << std::endl;

    return EXIT_SUCCESS;
}
