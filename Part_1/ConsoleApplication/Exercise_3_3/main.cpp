#include <iostream>
#include <string>
#include <windows.h>
#include <format>

//Задание 3 * .Гороскоп
//Пользователь вводит информацию о себе :
//
//пол;
//знак зодиака;
//возраст.
//Результат работы программы – предсказание.
//
//Если это мужчина водного знака зодиака и строго моложе 40 лет, то на экран должен вывестись текст :
//
//Сегодня очень плодотворный день.Можно добиться того, что прежде казалось почти невозможным.
//Если это женщина земляного знака зодиака и в возрасте от 15 до 30 лет, включая границы, то на экран должен вывестись текст :
//
//Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок.
//Будет не только весело, но и интересно : найдётся дело, которое увлечёт всех.
//В противном случае на экране должен появиться текст :
//
//Гороскоп для вас находится в разработке.Приходите чуточку позже;)
//Если будет желание и настроение, можно добавить свои собственные предсказания : )
//
//Пример
//Введите пол : м
//Введите знак зодиака : овен
//Введите возраст : 32
//Ваше предсказание :
//Гороскоп для вас находится в разработке.Приходите чуточку позже;)

const std::string INCORRECT_VALUE = "Некорректное значение !!!";
const std::string INCORRECT_GENDER_VALUE = "Введено некорректное значение пола !!!";
const std::string INCORRECT_AGE_VALUE = "Введено некорректное значение возраста !!!";


void InputValue(const std::string message, std::string &value) {
    std::cout << message;
    if (!std::getline(std::cin, value)) {
        throw std::runtime_error(INCORRECT_VALUE);
    }
    else {
        if (value.empty()) {
            throw std::runtime_error(INCORRECT_VALUE);
        }
    }
}

void InputValue(const std::string message, int& value) {
    std::string input;
    InputValue(message, input);

    try {
        value = std::stoi(input);
    }
    catch (const std::exception&) {
        throw std::runtime_error(INCORRECT_VALUE);
    }
}

bool isOneOf(const std::string& sign, const std::string& fisrt, const std::string& second, const std::string& third) {
    return ((sign == fisrt) || (sign == second) || (sign == third));
}

bool isOneOf(const std::string& sign, const std::string& fisrt) {
    return ((sign == fisrt));
}


void InputData(std::string& gender, std::string& sign, int& age) {
    std::string message = {};

    InputValue("Введите пол (м/ж): ", gender);
    if ((gender != "м" and gender != "ж")) {
        // message = std::format(INCORRECT_GENDER_VALUE, gender);
        message = std::format("Введено некорректное значение пола [{}] !!!", gender);
        throw std::runtime_error(message);
    }

    InputValue("Введите знак зодиака: ", sign);
    bool isWaterSign = isOneOf(sign, "рак", "скорпион", "рыбы");
    bool isEarthSign = isOneOf(sign, "телец", "дева", "козерог");
    bool isFireSign = isOneOf(sign, "овен", "лев", "стрелец");
    bool isAirSign = isOneOf(sign, "близнецы", "весы", "водолей");

    if (!(isWaterSign or isEarthSign or isFireSign or isAirSign)) {
        message = std::format("Введено некорректное значение знака зодиака [{}] !!!", sign);
        throw std::runtime_error(message);
    }

    InputValue("Введите возраст: ", age);
    if (!(age > 0 and age < 100)) {
        // message = std::format(INCORRECT_AGE_VALUE, age);
        message = std::format("Введено некорректное значение возраста [{}] !!!", age);
        throw std::runtime_error(message);
    }
};

void OutputData(const std::string& message, const std::string& gender, const std::string& sign, int& age) {
    std::string result = {};

    bool isWaterSign = isOneOf(sign, "рак", "скорпион", "рыбы");
    bool isEarthSign = isOneOf(sign, "телец", "дева", "козерог");
    bool isFireSign = isOneOf(sign, "овен", "лев", "стрелец");
    bool isAirSign = isOneOf(sign, "близнецы", "весы", "водолей");
    bool isMan = isOneOf(gender, "м");
    bool isWoman = isOneOf(gender, "ж");

    if (isMan and isWaterSign and age < 40) {
        result = "Сегодня очень плодотворный день.Можно добиться того, что прежде казалось почти невозможным.";
    }
    else if (isWoman and isEarthSign and age >= 15 and age <= 30) {
        result = 
          "Сегодняшний вечер подходит для общения с друзьями, проведения домашних праздников и импровизированных вечеринок.\n"
          "Будет не только весело, но и интересно : найдётся дело, которое увлечёт всех.";
    }
    else {
        result = "Гороскоп для вас находится в разработке.Приходите чуточку позже;)";
    }

    // Вывод результата.
    std::cout << message << std::endl;
    std::cout << result << std::endl;
};

int main()
{
    try
    {
        // Устанавливаем настройки консоли.
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);

        // Ввод данных. 
        std::string gender = {};
        std::string sign = {};
        int age = {};
        InputData(gender, sign, age);

        // Анализ данных и вывод результата.
        OutputData("Ваше предсказание : ", gender, sign, age);
    }
    catch (const std::exception& error)
    {
        std::cout << "Ошибка: " << error.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
