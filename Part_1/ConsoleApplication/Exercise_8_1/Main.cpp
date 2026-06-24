//Задача 1. Считающая функция
//Описание
//Нужно написать функцию, которая отслеживает, сколько раз она была вызвана за время работы программы.
//
//Посмотрите на этот код :
//
//int main(int argc, char** argv)
//{
//    for (int i = 0; i < 15; i++)
//    {
//        counting_function();
//    }
//}
//Ваша задача — написать функцию counting_function так, чтобы программа имела вывод на консоль, как показано ниже.
//
//Пример работы программы
//Количество вызовов функции counting_function() : 1
//Количество вызовов функции counting_function() : 2
//Количество вызовов функции counting_function() : 3
//Количество вызовов функции counting_function() : 4
//Количество вызовов функции counting_function() : 5
//Количество вызовов функции counting_function() : 6
//Количество вызовов функции counting_function() : 7
//Количество вызовов функции counting_function() : 8
//Количество вызовов функции counting_function() : 9
//Количество вызовов функции counting_function() : 10
//Количество вызовов функции counting_function() : 11
//Количество вызовов функции counting_function() : 12
//Количество вызовов функции counting_function() : 13
//Количество вызовов функции counting_function() : 14
//Количество вызовов функции counting_function() : 15

#include <iostream>

void counting_function()
{
    static int call_count = 0;  // Статическая переменная внутри функции
    call_count++;
    std::cout << "Количество вызовов функции counting_function(): " << call_count << std::endl;
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "Russian");
    for (int i = 0; i < 15; i++)
    {
        counting_function();
    }
    return 0;
}
