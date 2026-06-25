//Задача 3. Пользовательский массив в файл
//Описание
//Напишите программу, которая запрашивает у пользователя массив целых чисел и записывает его в файл в обратном порядке.
// Программа должна сначала спросить у пользователя размер предполагаемого массива, а затем попросить заполнить каждый его элемент.
// После этого программа должна записать размер полученного массива и сам полученный массив в обратном порядке в файл out.txt.
//
//Пример работы программы
//Консоль :
//
//Введите размер массива : 5
//arr[0] = 1
//arr[1] = 2
//arr[2] = 3
//arr[3] = 4
//arr[4] = 5
//Файл out.txt:
//
//5
//5 4 3 2 1
//Ещё один пример работы программы
//Консоль :
//
//Введите размер массива : 7
//arr[0] = 5
//arr[1] = 6
//arr[2] = 7
//arr[3] = 2
//arr[4] = 4
//arr[5] = 3
//arr[6] = 5
//Файл out.txt:
//
//7
//5 3 4 2 7 6 5

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdexcept>
#include "../Source/Utils.h"

/// <summary>
/// Запрашивает у пользователя массив целых чисел
/// </summary>
int* inputArrayFromUser(int& size) {
    std::cout << "Введите размер массива: ";
    std::cin >> size;

    if (size <= 0) {
        throw std::runtime_error("Размер массива должен быть положительным числом.");
    }

    int* arr = new int[size];

    for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }

    return arr;
}

/// <summary>
/// Сохраняет массив в файл в обратном порядке
/// </summary>
void saveArrayReversedToFile(const std::string& filename, const int* arr, int size) {
    std::string content;

    // Записываем размер массива
    content += std::to_string(size) + "\n";

    // Записываем массив в обратном порядке
    for (int i = size - 1; i >= 0; --i) {
        content += std::to_string(arr[i]);
        if (i > 0) {
            content += " ";
        }
    }
    content += "\n";

    saveTextToFile(filename, content);
}

/// <summary>
/// Выводит массив на экран
/// </summary>
void printArray(const int* arr, int size, const std::string& title = "") {
    if (!title.empty()) {
        std::cout << title << std::endl;
        std::cout << "----------------------------------------" << std::endl;
    }

    for (int i = 0; i < size; ++i) {
        std::cout << arr[i];
        if (i < size - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        int size = 0;
        int* arr = inputArrayFromUser(size);

        std::cout << std::endl;
        std::cout << "Введенный массив:" << std::endl;
        printArray(arr, size);

        std::string filename = getFullPathInExeFolder("out.txt");

        saveArrayReversedToFile(filename, arr, size);

        std::cout << std::endl;
        std::cout << "Массив сохранен в файл: " << filename << std::endl;

        std::cout << std::endl;
        displayFileContent(filename);

        // Освобождаем память
        delete[] arr;

    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}