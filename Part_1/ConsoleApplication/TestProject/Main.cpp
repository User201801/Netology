#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

// Структура для хранения состояния Вселенной
struct Universe {
    int rows;        // количество строк
    int cols;        // количество столбцов
    bool** grid;     // текущее состояние (true - жива, false - мертва)
    bool** nextGrid; // следующее состояние для вычислений
};

// Выделение памяти под двумерный массив
bool** allocateGrid(int rows, int cols) {
    bool** newGrid = new bool* [rows];
    for (int i = 0; i < rows; ++i) {
        newGrid[i] = new bool[cols];
        for (int j = 0; j < cols; ++j) {
            newGrid[i][j] = false;
        }
    }
    return newGrid;
}

// Освобождение памяти
void deallocateGrid(bool** grid, int rows) {
    if (grid) {
        for (int i = 0; i < rows; ++i) {
            delete[] grid[i];
        }
        delete[] grid;
    }
}

// Копирование содержимого одной сетки в другую
void copyGrid(bool** source, bool** destination, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            destination[i][j] = source[i][j];
        }
    }
}

// Инициализация Вселенной
void initUniverse(Universe& universe, int rows, int cols) {
    universe.rows = rows;
    universe.cols = cols;
    universe.grid = allocateGrid(rows, cols);
    universe.nextGrid = allocateGrid(rows, cols);
}

// Очистка Вселенной (освобождение памяти)
void clearUniverse(Universe& universe) {
    deallocateGrid(universe.grid, universe.rows);
    deallocateGrid(universe.nextGrid, universe.rows);
    universe.rows = 0;
    universe.cols = 0;
    universe.grid = nullptr;
    universe.nextGrid = nullptr;
}

// Копирование Вселенной
void copyUniverse(const Universe& source, Universe& destination) {
    // Очищаем старую память, если она есть
    if (destination.grid) {
        deallocateGrid(destination.grid, destination.rows);
        deallocateGrid(destination.nextGrid, destination.rows);
    }

    // Копируем размеры
    destination.rows = source.rows;
    destination.cols = source.cols;

    // Выделяем новую память
    destination.grid = allocateGrid(destination.rows, destination.cols);
    destination.nextGrid = allocateGrid(destination.rows, destination.cols);

    // Копируем данные
    copyGrid(source.grid, destination.grid, destination.rows, destination.cols);
    copyGrid(source.nextGrid, destination.nextGrid, destination.rows, destination.cols);
}

// Установить клетку как живую
void setCellAlive(Universe& universe, int row, int col) {
    if (row >= 0 && row < universe.rows && col >= 0 && col < universe.cols && universe.grid) {
        universe.grid[row][col] = true;
    }
}

// Получить состояние клетки
bool isAlive(const Universe& universe, int row, int col) {
    if (row < 0 || row >= universe.rows || col < 0 || col >= universe.cols || !universe.grid) {
        return false;
    }
    return universe.grid[row][col];
}

// Подсчитать количество живых соседей
int countLiveNeighbors(const Universe& universe, int row, int col) {
    int liveCount = 0;
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            if (dr == 0 && dc == 0) continue;
            int nr = row + dr;
            int nc = col + dc;
            if (isAlive(universe, nr, nc)) {
                liveCount++;
            }
        }
    }
    return liveCount;
}

// Вычислить следующее поколение
void computeNextGeneration(Universe& universe) {
    if (!universe.grid || !universe.nextGrid) return;

    for (int r = 0; r < universe.rows; ++r) {
        for (int c = 0; c < universe.cols; ++c) {
            int neighbors = countLiveNeighbors(universe, r, c);
            bool isCurrentlyAlive = universe.grid[r][c];
            bool willBeAlive = false;

            // Правила игры
            if (isCurrentlyAlive) {
                if (neighbors == 2 || neighbors == 3) {
                    willBeAlive = true;
                }
            }
            else {
                if (neighbors == 3) {
                    willBeAlive = true;
                }
            }
            universe.nextGrid[r][c] = willBeAlive;
        }
    }

    // Меняем местами указатели
    bool** temp = universe.grid;
    universe.grid = universe.nextGrid;
    universe.nextGrid = temp;
}

// Проверить, стабилизировалась ли Вселенная
bool isStable(const Universe& current, const Universe& previous) {
    if (previous.rows != current.rows || previous.cols != current.cols ||
        !current.grid || !previous.grid) return false;

    for (int r = 0; r < current.rows; ++r) {
        for (int c = 0; c < current.cols; ++c) {
            if (current.grid[r][c] != previous.grid[r][c]) {
                return false;
            }
        }
    }
    return true;
}

// Проверить, вымерла ли Вселенная
bool isExtinct(const Universe& universe) {
    if (!universe.grid) return true;
    for (int r = 0; r < universe.rows; ++r) {
        for (int c = 0; c < universe.cols; ++c) {
            if (universe.grid[r][c]) return false;
        }
    }
    return true;
}

// Подсчитать количество живых клеток
int getLiveCellCount(const Universe& universe) {
    if (!universe.grid) return 0;
    int count = 0;
    for (int r = 0; r < universe.rows; ++r) {
        for (int c = 0; c < universe.cols; ++c) {
            if (universe.grid[r][c]) count++;
        }
    }
    return count;
}

// Вывести состояние Вселенной
void displayUniverse(const Universe& universe, int generation) {
    if (!universe.grid) return;

    // Очищаем консоль.
    std::system("cls");

    std::cout << "Поколение: " << generation << std::endl;
    std::cout << "Живых клеток: " << getLiveCellCount(universe) << std::endl;
    for (int r = 0; r < universe.rows; ++r) {
        for (int c = 0; c < universe.cols; ++c) {
            std::cout << (universe.grid[r][c] ? "*" : "-") << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Чтение конфигурации из файла
bool readConfiguration(const std::string& filename, Universe& universe) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка: Не удалось открыть файл " << filename << std::endl;
        return false;
    }

    int rows, cols;
    if (!(file >> rows >> cols)) {
        std::cout << "Ошибка: Неверный формат файла." << std::endl;
        return false;
    }

    if (rows <= 0 || cols <= 0) {
        std::cout << "Ошибка: Размеры поля должны быть положительными." << std::endl;
        return false;
    }

    // Инициализируем Вселенную
    initUniverse(universe, rows, cols);

    int row, col;
    while (file >> row >> col) {
        if (row >= 0 && row < rows && col >= 0 && col < cols) {
            setCellAlive(universe, row, col);
        }
        else {
            std::cout << "Предупреждение: Координаты (" << row << ", " << col
                << ") выходят за пределы поля." << std::endl;
        }
    }

    file.close();
    return true;
}

// Создание файла-примера
void createExampleFile(const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Не удалось создать файл-пример" << std::endl;
        return;
    }

    // Пример из задания (планер)
    file << "20 30\n";
    file << "2 3\n";
    file << "2 4\n";
    file << "3 4\n";
    file << "3 5\n";
    file << "3 6\n";
    file << "3 7\n";
    file << "5 0\n";
    file << "5 1\n";
    file << "5 2\n";
    file << "6 2\n";
    file.close();

    std::cout << "Создан файл-пример: " << filename << std::endl;
    std::cout << "Формат: строки столбцы, затем пары координат живых клеток." << std::endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string filename = "life_config.txt";

    // Проверяем существование файла
    std::ifstream testFile(filename);
    if (!testFile.is_open()) {
        createExampleFile(filename);
    }
    testFile.close();

    // Создаем и инициализируем Вселенную
    Universe universe;
    universe.rows = 0;
    universe.cols = 0;
    universe.grid = nullptr;
    universe.nextGrid = nullptr;

    if (!readConfiguration(filename, universe)) {
        std::cout << "Не удалось прочитать конфигурацию. Программа завершена." << std::endl;
        return 1;
    }

    int generation = 0;
    bool gameOver = false;
    std::string endReason;

    // Отображаем начальное состояние
    displayUniverse(universe, generation);

    // Основной игровой цикл
    while (!gameOver) {
        // Сохраняем предыдущее состояние
        Universe previousUniverse;
        previousUniverse.rows = 0;
        previousUniverse.cols = 0;
        previousUniverse.grid = nullptr;
        previousUniverse.nextGrid = nullptr;
        copyUniverse(universe, previousUniverse);

        // Вычисляем следующее поколение
        computeNextGeneration(universe);
        generation++;

        // Проверяем условия завершения
        if (isExtinct(universe)) {
            gameOver = true;
            endReason = "Все клетки вымерли.";
        }
        else if (isStable(universe, previousUniverse)) {
            gameOver = true;
            endReason = "Достигнута стабильная конфигурация.";
        }

        // Отображаем новое состояние
        displayUniverse(universe, generation);

        // Очищаем память предыдущего состояния
        clearUniverse(previousUniverse);

        // Пауза
        if (!gameOver) {
          Sleep(1000);
        }
    }

    // Финальное сообщение
    std::cout << "=== ИГРА ЗАВЕРШЕНА ===" << std::endl;
    std::cout << "Причина: " << endReason << std::endl;
    std::cout << "Финальное поколение: " << generation << std::endl;
    std::cout << "Живых клеток: " << getLiveCellCount(universe) << std::endl;

    // Очищаем память
    clearUniverse(universe);

    return 0;
}