#include <iostream>
#include <string>
#include <windows.h>

//Задание 4 * .Сравнить числа
//Напишите программу, которая запрашивает у пользователя два целых числа меньше 100 и выводит на экран результат их сравнения в текстовом виде.
//
//Пример 1
//Введите целое число : 17
//Введите целое число : 36
//
//семнадцать меньше чем тридцать шесть
//Пример 2
//Введите целое число : 99
//Введите целое число : -36
//
//девяносто девять больше чем минус тридцать шесть
//Пример 3
//Введите целое число : 17
//Введите целое число : 17
//
//семнадцать равно семнадцать
//Пример 4
//Введите целое число : 17
//Введите целое число : -117
//
//Ошибка!Одно из чисел вне диапазона!
//Ограничения
//Программа может работать только с числами меньше 100 и больше - 100. Если хотя бы одно из введённых чисел не укладывается в этот диапазон, вместо результата программа должна сообщить пользователю об ошибке.

/// <summary>
/// Функция для преобразования единиц в текст.
/// </summary>
/// <param name="num">Число.</param>
std::string getUnit(int num) {
    switch (num) {
        case 0: return "ноль";
        case 1: return "один";
        case 2: return "два";
        case 3: return "три";
        case 4: return "четыре";
        case 5: return "пять";
        case 6: return "шесть";
        case 7: return "семь";
        case 8: return "восемь";
        case 9: return "девять";
        default: return "";
    }
}

/// <summary>
/// Функция для преобразования чисел от 10 до 19.
/// </summary>
/// <param name="num">Число.</param>
std::string getTeen(int num) {
    switch (num) {
        case 10: return "десять";
        case 11: return "одиннадцать";
        case 12: return "двенадцать";
        case 13: return "тринадцать";
        case 14: return "четырнадцать";
        case 15: return "пятнадцать";
        case 16: return "шестнадцать";
        case 17: return "семнадцать";
        case 18: return "восемнадцать";
        case 19: return "девятнадцать";
        default: return "";
    }
}

/// <summary>
/// Функция для преобразования десятков в текст.
/// </summary>
/// <param name="num">Число.</param>
std::string getTen(int num) {
    switch (num) {
    case 2: return "двадцать";
    case 3: return "тридцать";
    case 4: return "сорок";
    case 5: return "пятьдесят";
    case 6: return "шестьдесят";
    case 7: return "семьдесят";
    case 8: return "восемьдесят";
    case 9: return "девяносто";
    default: return "";
    }
}

/// <summary>
/// Функция для преобразования числа в текстовый вид.
/// </summary>
/// <param name="num">Число.</param>
std::string numberToText(int num) {
    if (num == 0) return "ноль";

    std::string result;
    bool isNegative = false;

    // Проверяем отрицательное ли число
    if (num < 0) {
        isNegative = true;
        num = abs(num);
    }

    // Преобразуем число в текст
    if (num >= 10 && num <= 19) {
        result = getTeen(num);
    }
    else {
        int ten = num / 10;
        int unit = num % 10;

        if (ten >= 2) {
            result = getTen(ten);
            if (unit > 0) {
                result += " " + getUnit(unit);
            }
        }
        else if (num < 10 && num > 0) {
            result = getUnit(num);
        }
    }

    // Добавляем "минус" если число отрицательное
    if (isNegative) {
        result = "минус " + result;
    }

    return result;
}

int main() {
    // Устанавливаем настройки консоли.
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int num1, num2;

    // Запрашиваем числа у пользователя
    std::cout << "Введите целое число: ";
    std::cin >> num1;
    std::cout << "Введите целое число: ";
    std::cin >> num2;

    // Проверяем диапазон чисел (-100, 100)
    if (num1 <= -100 || num1 >= 100 || num2 <= -100 || num2 >= 100) {
        std::cout << "Ошибка! Одно из чисел вне диапазона!\n"
            << "Ограничения\n"
            << "Программа может работать только с числами меньше 100 и больше - 100. "
                "Если хотя бы одно из введённых чисел не укладывается в этот диапазон, "
                "вместо результата программа должна сообщить пользователю об ошибке." << std::endl;
        return 0;
    }

    // Сравниваем числа и выводим результат
    std::string text1 = numberToText(num1);
    std::string text2 = numberToText(num2);

    // Используем switch для выбора типа сравнения
    int comparison = 0;
    if (num1 < num2) comparison = -1;
    else if (num1 > num2) comparison = 1;

    switch (comparison) {
    case -1:
        std::cout << text1 << " меньше чем " << text2 << std::endl;
        break;
    case 1:
        std::cout << text1 << " больше чем " << text2 << std::endl;
        break;
    case 0:
        std::cout << text1 << " равно " << text2 << std::endl;
        break;
    }

    return 0;
}
