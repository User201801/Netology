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
#include "../Source/Utils.cpp"  // Путь к Utils.h в папке Source

/// <summary>
/// Создает файл с примером данных, если он не существует
/// </summary>
void createExampleFile(const std::string& filename) {
    std::string content = "Картошка капуста\n";
    content += "Малина клубника черешня\n";
    content += "Яблоко груша апельсин\n";

    if (saveTextToFile(filename, content)) {
        std::cout << "Создан файл-пример: " << filename << std::endl;
    }
    else {
        std::cout << "Ошибка: Не удалось создать файл-пример" << std::endl;
    }
}

/// <summary>
/// Выводит содержимое файла на консоль, каждое слово на отдельной строке
/// </summary>
void printFileContent(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Ошибка: Не удалось открыть файл " << filename << std::endl;
        return;
    }

    std::string word;

    // Читаем файл по словам и выводим каждое на отдельной строке
    while (file >> word) {
        std::cout << word << std::endl;
    }

    file.close();
}

int main() {
    // Устанавливаем кодировку для корректного отображения русского языка
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string filename = "in.txt";

    // Проверяем существование файла
    std::ifstream testFile(filename);
    if (!testFile.is_open()) {
        testFile.close();
        createExampleFile(filename);
    }
    else {
        testFile.close();
    }

    std::cout << "Содержимое файла " << filename << " (каждое слово на отдельной строке):" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // Выводим содержимое файла
    printFileContent(filename);

    return 0;
}