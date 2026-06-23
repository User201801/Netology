//Задача 2. Одинаковые, но разные функции
//Описание
//Ваша задача — создать несколько функций с одинаковой сигнатурой, то есть с одинаковым именем, одинаковыми параметрами и одинаковым типом возвращаемого значения, но с разной реализацией.
//
//Создайте четыре функции int calc(int x, int y), каждая из которых будет реализовывать одно из четырёх простых арифметических действий : сложение, вычитание, умножение, деление.
//
//В функции main напишите код, который использует каждую из четырёх функций и выводит результат на экран.В функции передавайте два числа, которые перед этим тоже выведите на экран, чтобы можно было убедиться в корректности операции.
//
//Пример работы программы
//x = 6, y = 9
//Сложение : 15
//Вычитание : -3
//Умножение : 54
//Деление : 0

#include <iostream>

namespace Addition {
    int calc(int x, int y) {
        return x + y;
    }
}

namespace Subtraction {
    int calc(int x, int y) {
        return x - y;
    }
}

namespace Multiplication {
    int calc(int x, int y) {
        return x * y;
    }
}

namespace Division {
    int calc(int x, int y) {
        if (y != 0) {
            return x / y;
        }
        std::cerr << "Ошибка: деление на ноль!" << std::endl;
        return 0;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    int x = 6, y = 9;

    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "Сложение: " << Addition::calc(x, y) << std::endl;
    std::cout << "Вычитание: " << Subtraction::calc(x, y) << std::endl;
    std::cout << "Умножение: " << Multiplication::calc(x, y) << std::endl;
    std::cout << "Деление: " << Division::calc(x, y) << std::endl;

    return 0;
}