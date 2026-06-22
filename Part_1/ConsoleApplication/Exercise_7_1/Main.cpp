//Задача 1. Адреса переменных
//Описание
//В этом задании вы потренируетесь выводить адреса и размеры переменных.Ваша задача — создать переменные следующих типов :
//
//int;
//short;
//long;
//long long;
//float;
//double;
//long double;
//bool.
//Для каждой переменной выведите на консоль её адрес и размер.
//
//Пример работы программы
//short: 007DF924 2
//int : 007DF918 4
//long : 007DF90C 4
//long long : 007DF8FC 8
//float : 007DF8F0 4
//double : 007DF8E0 8
//long double : 007DF8D0 8
//bool : 007DF8C7 1


#include <iostream>

int main() {
    setlocale(LC_ALL, "Russian");

    // Создаем переменные всех типов
    short s = 0;
    int i = 0;
    long l = 0;
    long long ll = 0;
    float f = 0.0f;
    double d = 0.0;
    long double ld = 0.0;
    bool b = false;

    // Выводим адреса и размеры
    std::cout << "short: " << &s << " " << sizeof(s) << std::endl;
    std::cout << "int: " << &i << " " << sizeof(i) << std::endl;
    std::cout << "long: " << &l << " " << sizeof(l) << std::endl;
    std::cout << "long long: " << &ll << " " << sizeof(ll) << std::endl;
    std::cout << "float: " << &f << " " << sizeof(f) << std::endl;
    std::cout << "double: " << &d << " " << sizeof(d) << std::endl;
    std::cout << "long double: " << &ld << " " << sizeof(ld) << std::endl;
    std::cout << "bool: " << &b << " " << sizeof(b) << std::endl;

    return 0;
}