#include <fstream>  // для std::ofstream
#include <string>   // для std::string
#include <iostream>

/// <summary>
/// Сохраняет текст в файл
/// </summary>
/// <param name="filename">Имя файла для сохранения</param>
/// <param name="text">Текст для записи в файл</param>
/// <returns>true если файл успешно создан и текст записан, false в случае ошибки</returns>
bool saveTextToFile(const std::string& filename, const std::string& text) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    file << text;
    file.close();

    return true;
}

/// <summary>
/// Выводит содержимое файла на консоль, каждое слово на отдельной строке
/// </summary>
void printFileContent(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Ошибка: Не удалось открыть файл " << filename << std::endl;
        return;
    }

    std::string word;

    // Читаем файл по словам и выводим каждое на отдельной строке
    while (file >> word) {
        std::cout << word << std::endl;
    }

    file.close();
}