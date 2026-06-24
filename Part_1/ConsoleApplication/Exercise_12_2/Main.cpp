//Задача 2. Чтение массива из файла
//Описание
//Напишите программу, которая открывает файл in.txt, содержащий массив целых чисел, и выводит на консоль этот массив в обратном порядке.
// Первое «слово» входящего файла — это число элементов массива.Дальше следует сам массив.
//
//Пример работы программы
//Содержимое файла in.txt:
//
//5
//1 2 3 4 5
//Вывод на консоль
//
//5 4 3 2 1
//Ещё один пример работы программы
//Содержимое файла in.txt:
//
//7
//6 5 3 8 2 5 8
//Вывод на консоль
//
//8 5 2 8 3 5 6

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "../Source/Utils.h"


void createExampleFile(const std::string& filename) {
    std::string content = "7\n";
    content += "6 5 3 8 2 5 8\n";
    saveTextToFile(filename, content);  // Единый стиль
    std::cout << "Создан файл-пример: " << filename << std::endl;
}

/// <summary>
/// Читает массив из файла и возвращает указатель на динамический массив
/// </summary>
int* readArrayFromFile(const std::string& filename, int& size) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    // Считываем размер массива
    if (!(file >> size)) {
        file.close();
        throw std::runtime_error("Неверный формат файла. Ожидается число.");
    }

    if (size <= 0) {
        file.close();
        throw std::runtime_error("Размер массива должен быть положительным числом.");
    }

    // Выделяем память
    int* arr = new int[size];

    // Считываем элементы
    for (int i = 0; i < size; ++i) {
        if (!(file >> arr[i])) {
            delete[] arr;
            file.close();
            throw std::runtime_error("Недостаточно элементов в файле.");
        }
    }

    file.close();
    return arr;
}

/// <summary>
/// Выводит массив в обратном порядке
/// </summary>
void printArrayReversed(const int* arr, int size) {
    if (size <= 0) {
        std::cout << "Массив пуст" << std::endl;
        return;
    }

    for (int i = size - 1; i >= 0; --i) {
        std::cout << arr[i];
        if (i > 0) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
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

        int size = 0;
        int* arr = readArrayFromFile(filename, size);

        std::cout << "Массив в обратном порядке:" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        printArrayReversed(arr, size);

        // Освобождаем память
        delete[] arr;

    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}