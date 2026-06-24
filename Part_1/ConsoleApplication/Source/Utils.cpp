#include <fstream>  // для std::ofstream
#include <string>   // для std::string

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