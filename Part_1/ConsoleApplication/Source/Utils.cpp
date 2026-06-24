#include "Utils.h"
#include <fstream>
#include <iostream>
#include <windows.h>
#include <filesystem>

void saveTextToFile(const std::string& filename, const std::string& text) {
    // Создаем все папки в пути
    std::filesystem::path filePath(filename);
    std::filesystem::path parentPath = filePath.parent_path();

    if (!parentPath.empty() && !std::filesystem::exists(parentPath)) {
        if (!std::filesystem::create_directories(parentPath)) {
            throw std::runtime_error("Не удалось создать папки для файла: " + filename);
        }
    }

    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Не удалось создать файл: " + filename);
    }

    file << text;
    file.close();
}

void printFileContent(const std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        throw std::runtime_error("Не удалось открыть файл: " + filename);
    }

    std::string word;

    while (file >> word) {
        std::cout << word << std::endl;
    }

    file.close();
}

std::string getFullPathInExeFolder(const std::string& filename) {
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string exePath(buffer);

    size_t pos = exePath.find_last_of("\\/");
    if (pos != std::string::npos) {
        exePath = exePath.substr(0, pos);
    }

    return exePath + "\\" + filename;
}