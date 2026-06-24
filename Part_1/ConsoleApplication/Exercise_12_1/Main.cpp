//Задача 1. Вывод файла
//Описание
//Напишите программу, которая открывает файл и выводит его содержимое на консоль.Каждое слово выводится на отдельной строке.
//
//Пример работы программы
//Содержимое файла in.txt:
//
//Картошка капуста
//Малина клубника черешня
//Яблоко груша апельсин
//Вывод на консоль
//
//Картошка
//капуста
//Малина
//клубника
//черешня
//Яблоко
//груша
//апельсин

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdexcept>
#include "../Source/Utils.h"

int main() {
    // Устанавливаем кодировку
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        std::string fullPath = getFullPathInExeFolder("Temp\\in.txt");

        std::cout << "Путь к файлу: " << fullPath << std::endl;
        std::cout << std::endl;

        // Проверяем существование файла
        std::ifstream testFile(fullPath);
        if (!testFile.is_open()) {
            testFile.close();

            // Создаем файл с примером данных
            std::string content = "Картошка капуста\n";
            content += "Малина клубника черешня\n";
            content += "Яблоко груша апельсин\n";

            saveTextToFile(fullPath, content);
            std::cout << "Создан файл-пример: " << fullPath << std::endl;
        }
        else {
            testFile.close();
        }

        std::cout << "Содержимое файла (каждое слово на отдельной строке):" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        printFileContent(fullPath);

    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}