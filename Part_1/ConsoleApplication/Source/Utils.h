#pragma once
#include <string>
#include <stdexcept>

/// <summary>
/// Сохраняет текст в файл, автоматически создавая все необходимые папки
/// </summary>
/// <param name="filename">Полный путь к файлу для сохранения</param>
/// <param name="text">Текст для записи в файл</param>
/// <exception cref="std::runtime_error">Выбрасывает исключение при ошибке</exception>
void saveTextToFile(const std::string& filename, const std::string& text);

/// <summary>
/// Выводит содержимое файла на консоль, каждое слово на отдельной строке
/// </summary>
void printFileContent(const std::string& filename);

/// <summary>
/// Возвращает полный путь к файлу, привязанный к каталогу с исполняемым файлом
/// </summary>
std::string getFullPathInExeFolder(const std::string& filename);