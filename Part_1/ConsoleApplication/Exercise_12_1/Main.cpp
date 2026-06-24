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


void createExampleFile(const std::string& filename) {
    // Создаем файл с примером данных
    std::string content = "Картошка капуста\n";
    content += "Малина клубника черешня\n";
    content += "Яблоко груша апельсин\n";

    saveTextToFile(filename, content);
    std::cout << "Создан файл-пример: " << filename << std::endl;
}

int main() {
    // Устанавливаем кодировку
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        std::string filename = getFullPathInExeFolder("Temp\\in.txt");

        std::cout << "Содержимое файла " << filename << ":" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        // Создаем файл источник.
        std::ifstream testFile(filename);
        if (!testFile.is_open()) {
            createExampleFile(filename);
        }
        else {
            testFile.close();
        }

        // Выводим содержимое файла построчно с номерами строк.
        displayFileContent(filename);

        std::cout << "----------------------------------------" << std::endl;

        std::cout << "Содержимое файла (каждое слово на отдельной строке):" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        printFileContent(filename);

    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}