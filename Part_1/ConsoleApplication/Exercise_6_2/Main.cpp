//Описание
//Дана программа :
//
//#include <iostream>
//
//int main(int argc, char** argv)
//{
//    int value = 5, power = 2, result = 1;
//
//    for (int i = 0; i < power; i++)
//    {
//        result *= value;
//    }
//
//    std::cout << value << " в степени " << power << " = " << result << std::endl;
//
//    value = 3;
//    power = 3;
//    result = 1;
//
//    for (int i = 0; i < power; i++)
//    {
//        result *= value;
//    }
//
//    std::cout << value << " в степени " << power << " = " << result << std::endl;
//
//    value = 4;
//    power = 4;
//    result = 1;
//
//    for (int i = 0; i < power; i++)
//    {
//        result *= value;
//    }
//
//    std::cout << value << " в степени " << power << " = " << result << std::endl;
//
//    return 0;
//}
//
//
//Определите, что она делает, и найдите дублирующийся код.Создайте функцию, которая будет устранять дублирование, и вместо повторяющегося кода вызывайте её.Результат работы программы не должен измениться.
//
//Пример работы программы
//5 в степени 2 = 25
//3 в степени 3 = 27
//4 в степени 4 = 256


#include <iostream>

// Функция возведения в степень
int power(int value, int power) {
    int result = 1;
    for (int i = 0; i < power; i++) {
        result *= value;
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "5 в степени 2 = " << power(5, 2) << std::endl;
    std::cout << "3 в степени 3 = " << power(3, 3) << std::endl;
    std::cout << "4 в степени 4 = " << power(4, 4) << std::endl;

    return 0;
}