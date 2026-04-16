//Задание 2. Упорядочить числа
//Напишите программу, которая запрашивает у пользователя три целых числа и выводит их на экран в порядке убывания.
//
//Пример
//Введите первое число : 1
//Введите второе число : -2
//Введите третье число : 3
//
//Результат : 3 1 - 2
//Ограничения *
//Для решения задачи используйте только оператор ? : .

#include <iostream>
#include <windows.h>
#include <format>

const std::string INCORRECT_VALUE = "Некорректное значение !!!";
const std::string INCORRECT_CONDITIONS = "По условиям задачи - числа должно быть 3";

/// <summary>
/// Чтение целочисленных значений с консоли, с вызовом исключений в случае ошибки.
/// </summary>
/// <param name="message">Сообщение.</param>
/// <param name="value">Целочисленное значение.</param>
void InputValue(const std::string message, int& value) {
    std::cout << message;
    if (!(std::cin >> value)) {
        throw std::runtime_error(INCORRECT_VALUE);
    }
    else {
        char char_var = std::cin.peek();
        if (char_var != '\n') {
            throw std::runtime_error(INCORRECT_VALUE);
        }
    }
}

/// <summary>
/// Вывод содержимого массива в одну строку.
/// </summary>
/// <param name="arr">Указатель на массив.</param>
/// <param name="size">Размер массива.</param>
void OutArrayToString(int arr[], int size) {
    for (size_t i = 0; i < (size); i++)
    {
        std::cout << "arr[" << i << "] = " << arr[i] << ", ";
    }
    std::cout << std::endl;
}

/// <summary>
///  Вывод значений массива в порядке убывания с помощью условного оператора IfElse.
/// </summary>
/// <param name="message">Сообщение.</param>
/// <param name="arr">Указатель на массив.</param>
/// <param name="size">Размер массива.</param>
void OutIfElse(const std::string message, int arr[], int size) {
    // Рассматриваю массив не как массив, а как 3 независимых целых числа.  
    std::cout << message;
    if (!(size == 3)) {
        // Закладываю ограничение на текущую задачу. 
        throw std::runtime_error(INCORRECT_CONDITIONS);
    }
    else {
        if ((arr[0] >= arr[1]) and (arr[0] >= arr[2])) {
            // arr[0] - наибольшее
            std::cout << arr[0] << ",";
            if (arr[1] >= arr[2]) {
                std::cout << arr[1] << ",";
                std::cout << arr[2];
            }
            else {
                std::cout << arr[2] << ",";
                std::cout << arr[1];
            }
        }
        else if ((arr[1] >= arr[0]) and (arr[1] >= arr[2])) {
            // arr[1] - наибольшее
            std::cout << arr[1] << ",";
            if (arr[0] >= arr[2]) {
                std::cout << arr[0] << ",";
                std::cout << arr[2];
            }
            else {
                std::cout << arr[2] << ",";
                std::cout << arr[0];
            }
        }
        else {
            // arr[2] - наибольшее
            std::cout << arr[2] << ",";
            if (arr[0] >= arr[1]) {
                std::cout << arr[0] << ",";
                std::cout << arr[1];
            }
            else {
                std::cout << arr[1] << ",";
                std::cout << arr[0];
            }
        }
        std::cout << std::endl;
    }
}

/// <summary>
/// Вывод значений массива в порядке убывания с помощью тернарного оператора.
/// </summary>
/// <param name="message">Сообщение.</param>
/// <param name="arr">Указатель на массив.</param>
/// <param name="size">Размер массива.</param>
void OutTernary(const std::string message, int arr[], int size) {
    // Рассматриваю массив не как массив, а как 3 независимых целых числа.  
    //std::cout << message;
    if (!(size == 3)) {
        // Закладываю ограничение на текущую задачу. 
        throw std::runtime_error(INCORRECT_CONDITIONS);
    }
    else {
        int max = (arr[0] > arr[1]) ?
            ((arr[0] > arr[2]) ? arr[0] : arr[2]) :
            ((arr[1] > arr[2]) ? arr[1] : arr[2]);
        int min = (arr[0] < arr[1]) ?
            ((arr[0] < arr[2]) ? arr[0] : arr[2]) :
            ((arr[1] < arr[2]) ? arr[1] : arr[2]);

        int middle = (arr[0] + arr[1] + arr[2]) - min - max;

        // std::cout << max << "," << middle << "," << min;
        std::cout << std::format("{}{},{},{}", message, max, middle, min) << std::endl;
    }
}

int main() 
{
    // Устанавливаем настройки консоли.
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Инициализируем статистический C-Style массив состоящий из 3 элементов. 
    // Каждый элемент задается целым числом. Первоначальный массив инициализируем 0.
    // Память освобождать не надо, делается автоматически. 
    // Не стал делать обычными переменными, так как было лень делать 3 объявления. 
    int arr[3] = {};

    try 
    {
        // Заполняем C-Style массив.  
        InputValue("Введите первое число: ", arr[0]);
        InputValue("Введите второе число: ", arr[1]);
        InputValue("Введите третье число: ", arr[2]);

        // Выводим введенные данные.
        int sizeArray = sizeof(arr) / sizeof(arr[0]);
        OutArrayToString(arr, sizeArray);

        // 1. Выводим в порядке убывания с помощью if-else.
        OutIfElse("Вывод значений в порядке убывания с помощью if-else: ", arr, sizeArray);

        // Выводим в порядке убывания с помощью тернарного оператора. Ternary operator (также известен как conditional operator)
        OutTernary("Вывод значений в порядке убывания с помощью тернарного оператора: ", arr, sizeArray);

    }      
    catch (const std::exception& error)
    {
        std::cout << "Ошибка: " << error.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

