//Задача 2. Сумма цифр числа
//Описание
//Напишите программу, которая запрашивает у пользователя целое число и выводит на экран сумму всех его цифр.
//
//Примеры работы программы
//Введите целое число :
//7345
//Сумма цифр : 19
//Введите целое число :
//1234
//Сумма цифр : 10

#include <iostream>
#include <cmath>
#include <windows.h>

// Функция для подсчета суммы цифр
int sumOfDigits(int number) {
    int sum = 0;
    number = std::abs(number);  // Работаем с положительным числом

    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int number = 0;

    std::cout << "Введите целое число: ";
    std::cin >> number;

    int result = sumOfDigits(number);

    std::cout << "Сумма цифр: " << result << std::endl;

    return 0;
}
