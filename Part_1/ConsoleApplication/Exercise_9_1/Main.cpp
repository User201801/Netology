//Задача 1. Вывод массива
//Описание
//Напишите функцию print, которая принимает на вход массив произвольного размера и выводит его на экран.В программе создайте несколько массивов разного размера и используйте для вызова вашей функции.
//
//Пример работы программы
//1 2 3 4 5 6 7 8 9
//6 5 4 8
//1 4 3 7 5

#include <iostream>

void print(const int* arr, int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << (i < size - 1 ? " " : "");
    }
    std::cout << std::endl;
}

int main() {
    int arr1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int arr2[] = { 6, 5, 4, 8 };
    int arr3[] = { 1, 4, 3, 7, 5 };

    print(arr1, sizeof(arr1) / sizeof(arr1[0]));
    print(arr2, sizeof(arr2) / sizeof(arr2[0]));
    print(arr3, sizeof(arr3) / sizeof(arr3[0]));

    return 0;
}