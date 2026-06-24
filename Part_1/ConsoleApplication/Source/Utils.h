#pragma once   //это директива, которая предотвращает многократное включение одного и того же заголовочного файла.
#include <string>

/// <summary>
/// Сохраняет текст в файл
/// </summary>
/// <param name="filename">Имя файла для сохранения</param>
/// <param name="text">Текст для записи в файл</param>
/// <returns>true если файл успешно создан и текст записан, false в случае ошибки</returns>
bool saveTextToFile(const std::string& filename, const std::string& text);

/// <summary>
/// Выводит содержимое файла на консоль, каждое слово на отдельной строке
/// </summary>
void printFileContent(const std::string& filename);
