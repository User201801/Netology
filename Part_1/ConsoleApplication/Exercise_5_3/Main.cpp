//Задача 3. Двумерный массив
//Описание
//Напишите программу, которая создаёт и инициализирует двумерный массив целых чисел размерностью 3х6, выводит на экран все элементы массива в виде таблички, находит индексы минимального и максимального элементов массива и выводит их на экран.Числа для заполнения массива придумайте сами.
//
//Чтобы элементы массива выводились равномерно, внутри одной строчки разделяйте их символом табуляции \t вместо пробела.
//
//Пример работы программы
//Массив :
//1  2  3  4  5  6
//7  8  9  10 11 12
//13 14 15 16 17 18
//Индекс минимального элемента : 0 0
//Индекс максимального элемента : 2 5

#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    setlocale(LC_ALL, "Russian");

    const int ROWS = 3;
    const int COLS = 6;
    int arr[ROWS][COLS];

    // Инициализация генератора случайных чисел
    srand(time(nullptr));

    // Заполняем случайными числами от 1 до 100
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = rand() % 100 + 1;
        }
    }

    int minRow = 0, minCol = 0;
    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (arr[i][j] < arr[minRow][minCol]) {
                minRow = i;
                minCol = j;
            }
            if (arr[i][j] > arr[maxRow][maxCol]) {
                maxRow = i;
                maxCol = j;
            }
        }
    }

    std::cout << "Массив:" << std::endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "Индекс минимального элемента: " << minRow << " " << minCol << std::endl;
    std::cout << "Индекс максимального элемента: " << maxRow << " " << maxCol << std::endl;

    return 0;
}