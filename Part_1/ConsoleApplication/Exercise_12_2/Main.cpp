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

/// <summary>
/// Создает файл с примером данных, если он не существует
/// </summary>
void createExampleFile(const std::string& filename) {
    std::string content = "5\n";
    content += "1 2 3 4 5\n";

    if (saveTextToFile(filename, content)) {
        std::cout << "Создан файл-пример: " << filename << std::endl;
    }
    else {
        std::cout << "Ошибка: Не удалось создать файл-пример" << std::endl;
    }
}

/// <summary>
/// Читает массив из файла и выводит его в обратном порядке
/// </summary>
void printArrayReversed(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Ошибка: Не удалось открыть файл " << filename << std::endl;
        return;
    }

    int size;

    // Считываем размер массива (первое число в файле)
    if (!(file >> size)) {
        std::cout << "Ошибка: Неверный формат файла. Ожидается число." << std::endl;
        file.close();
        return;
    }

    // Проверяем корректность размера
    if (size <= 0) {
        std::cout << "Ошибка: Размер массива должен быть положительным числом." << std::endl;
        file.close();
        return;
    }

    // Выделяем память под динамический массив
    int* arr = new int[size];

    // Считываем элементы массива
    for (int i = 0; i < size; ++i) {
        if (!(file >> arr[i])) {
            std::cout << "Ошибка: Недостаточно элементов в файле." << std::endl;
            delete[] arr;  // Освобождаем память
            file.close();
            return;
        }
    }

    file.close();

    // Выводим массив в обратном порядке
    for (int i = size - 1; i >= 0; --i) {
        std::cout << arr[i];
        if (i > 0) {
            std::cout << " ";  // Добавляем пробел между числами
        }
    }
    std::cout << std::endl;

    // Освобождаем память
    delete[] arr;
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

    std::cout << "Массив в обратном порядке:" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // Читаем и выводим массив в обратном порядке
    printArrayReversed(filename);

    system("pause");
    return 0;
}