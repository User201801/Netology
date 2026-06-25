//Задача 4. Считывание двумерного массива из файла
//Описание
//Напишите программу, которая считывает из файла in.txt двумерный массив и выводит его на консоль.При этом каждая строка должна быть развёрнута в обратную сторону.Файл in.txt устроен следующим образом : первые два числа — это число строк и число столбцов двумерного массива.Далее идёт сам двумерный массив в виде таблицы.
//
//Пример работы программы
//Файл in.txt :
//
//	2 3
//	1 2 3
//	4 5 6
//	Вывод на консоль :
//
//3 2 1
//6 5 4
//Ещё один пример работы программы
//Файл in.txt :
//
//	5 5
//	1 2 3 4 5
//	6 7 8 9 10
//	11 12 13 14 15
//	16 17 18 19 20
//	21 22 23 24 25
//	Вывод на консоль :
//
//5 4 3 2 1
//10 9 8 7 6
//15 14 13 12 11
//20 19 18 17 16
//25 24 23 22 21
//

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include <stdexcept>
#include "../Source/Utils.h"

/// <summary>
/// Создает файл с примером данных, если он не существует
/// </summary>
void createExampleFile(const std::string& filename) {
    std::string content = "2 3\n";
    content += "1 2 3\n";
    content += "4 5 6\n";

    saveTextToFile(filename, content);
    std::cout << "Создан файл-пример: " << filename << std::endl;
}

/// <summary>
/// Выделяет память под двумерный массив
/// </summary>
int** allocateMatrix(int rows, int cols) {
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

/// <summary>
/// Освобождает память двумерного массива
/// </summary>
void freeMatrix(int** matrix, int rows) {
    if (matrix) {
        for (int i = 0; i < rows; ++i) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}

/// <summary>
/// Читает двумерный массив из файла
/// </summary>
int** readMatrixFromFile(const std::string& filename, int& rows, int& cols) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    // Считываем размеры
    if (!(file >> rows >> cols)) {
        file.close();
        throw std::runtime_error("Неверный формат файла. Ожидаются два числа: строки и столбцы.");
    }

    if (rows <= 0 || cols <= 0) {
        file.close();
        throw std::runtime_error("Размеры матрицы должны быть положительными числами.");
    }

    // Выделяем память
    int** matrix = allocateMatrix(rows, cols);

    // Считываем элементы матрицы
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (!(file >> matrix[i][j])) {
                freeMatrix(matrix, rows);
                file.close();
                throw std::runtime_error("Недостаточно элементов в файле.");
            }
        }
    }

    file.close();
    return matrix;
}

/// <summary>
/// Выводит матрицу на консоль с развернутыми строками
/// </summary>
void printMatrixReversedRows(int** matrix, int rows, int cols) {
    if (!matrix || rows <= 0 || cols <= 0) {
        std::cout << "Матрица пуста" << std::endl;
        return;
    }

    for (int i = 0; i < rows; ++i) {
        for (int j = cols - 1; j >= 0; --j) {
            std::cout << matrix[i][j];
            if (j > 0) {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    try {
        std::string filename = getFullPathInExeFolder("Temp//in.txt");

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

        // Выводим содержимое файла построчно.
        displayFileContent(filename);

        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Матрица с развернутыми строками:" << std::endl;
        std::cout << "----------------------------------------" << std::endl;

        int rows = 0;
        int cols = 0;
        int** matrix = readMatrixFromFile(filename, rows, cols);

        // Выводим матрицу с развернутыми строками
        printMatrixReversedRows(matrix, rows, cols);

        // Освобождаем память
        freeMatrix(matrix, rows);

    }
    catch (const std::exception& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}