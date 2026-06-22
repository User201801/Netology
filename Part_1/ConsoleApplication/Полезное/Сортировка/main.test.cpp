#include "sorting.h"
#include <chrono>
#include <iomanip>

using namespace std;

// Перечисление всех типов сортировки
enum SortType {
    BUBBLE,
    INSERTION,
    SELECTION,
    SHELL,
    MERGE,
    QUICK,
    HEAP,
    COUNTING
};

// Структура для хранения результата теста
struct TestResult {
    string name;
    long long time;
    bool sorted;
    bool correct;
};

// Функция для измерения времени выполнения
template<typename Func>
TestResult testSort(const string& name, Func sortFunc, vector<int> arr) {
    auto start = chrono::high_resolution_clock::now();
    sortFunc(arr);
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
    
    TestResult result;
    result.name = name;
    result.time = duration.count();
    result.sorted = Sorting::isSorted(arr);
    result.correct = result.sorted; // Можно добавить проверку на правильность
    return result;
}

// Функция для тестирования всех сортировок
void testAllSorts(const vector<int>& originalArr) {
    cout << "\n╔════════════════════════════════════════════════════════════╗\n";
    cout << "║              ТЕСТИРОВАНИЕ АЛГОРИТМОВ СОРТИРОВКИ          ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n\n";
    
    cout << "Размер массива: " << originalArr.size() << " элементов\n\n";
    
    cout << "Исходный массив (первые 20 элементов): ";
    vector<int> display = originalArr;
    if (display.size() > 20) display.resize(20);
    Sorting::printArray(display);
    cout << "...\n\n";
    
    vector<TestResult> results;
    vector<int> arr;
    
    // Тестируем каждую сортировку
    cout << "┌─────────────────────┬───────────┬──────────┬─────────┐\n";
    cout << "│ Алгоритм            │ Время(мкс)│ Статус   │ Результат│\n";
    cout << "├─────────────────────┼───────────┼──────────┼─────────┤\n";
    
    // 1. Пузырьком
    Sorting::copyArray(originalArr, arr);
    results.push_back(testSort("Пузырьком", Sorting::bubbleSort, arr));
    
    // 2. Вставкой
    Sorting::copyArray(originalArr, arr);
    results.push_back(testSort("Вставкой", Sorting::insertionSort, arr));
    
    // 3. Выбором
    Sorting::copyArray(originalArr, arr);
    results.push_back(testSort("Выбором", Sorting::selectionSort, arr));
    
    // 4. Шелла
    Sorting::copyArray(originalArr, arr);
    results.push_back(testSort("Шелла", Sorting::shellSort, arr));
    
    // 5. Слиянием
    Sorting::copyArray(originalArr, arr);
    results.push_back(testSort("Слиянием", Sorting::mergeSort, arr));
    
    // 6. Быстрая
    Sorting::copyArray(originalArr, arr);
    results.push_back(testSort("Быстрая", Sorting::quickSort, arr));
    
    // 7. Пирамидальная
    Sorting::copyArray(originalArr, arr);
    results.push_back(testSort("Пирамидал.", Sorting::heapSort, arr));
    
    // 8. Подсчётом
    Sorting::copyArray(originalArr, arr);
    results.push_back(testSort("Подсчётом", Sorting::countingSort, arr));
    
    // Выводим результаты в виде таблицы
    for (const auto& result : results) {
        cout << "│ " << left << setw(19) << result.name << " │ ";
        cout << right << setw(9) << result.time << " │ ";
        cout << (result.sorted ? "✓ Отсорт." : "✗ Ошибка") << " │ ";
        cout << (result.correct ? "✓ OK" : "✗ FAIL") << " │\n";
    }
    cout << "└─────────────────────┴───────────┴──────────┴─────────┘\n";
}

// Тест на производительность
void performanceTest() {
    cout << "\n\n╔════════════════════════════════════════════════════════════╗\n";
    cout << "║           ТЕСТ НА ПРОИЗВОДИТЕЛЬНОСТЬ                    ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    vector<int> sizes = {100, 500, 1000, 5000, 10000};
    
    cout << "\nРазмеры массивов для теста: ";
    for (int size : sizes) {
        cout << size << "  ";
    }
    cout << "\n\n";
    
    cout << "┌─────────────┬──────────┬──────────┬──────────┬──────────┬──────────┐\n";
    cout << "│ Алгоритм    │   100    │   500    │   1000   │  5000    │  10000   │\n";
    cout << "├─────────────┼──────────┼──────────┼──────────┼──────────┼──────────┤\n";
    
    // Словарь для хранения функций сортировки
    vector<pair<string, void(*)(vector<int>&)>> sorts = {
        {"Пузырьком", Sorting::bubbleSort},
        {"Вставкой", Sorting::insertionSort},
        {"Выбором", Sorting::selectionSort},
        {"Шелла", Sorting::shellSort},
        {"Слиянием", Sorting::mergeSort},
        {"Быстрая", Sorting::quickSort},
        {"Пирамид.", Sorting::heapSort},
        {"Подсчётом", Sorting::countingSort}
    };
    
    for (const auto& sortPair : sorts) {
        cout << "│ " << left << setw(11) << sortPair.first << " │ ";
        
        for (int size : sizes) {
            vector<int> arr = Sorting::generateRandomArray(size, 0, 1000);
            vector<int> copy;
            
            auto start = chrono::high_resolution_clock::now();
            sortPair.second(arr);
            auto end = chrono::high_resolution_clock::now();
            auto duration = chrono::duration_cast<chrono::microseconds>(end - start);
            
            if (duration.count() < 1000) {
                cout << right << setw(8) << duration.count() << "мкс │ ";
            } else {
                cout << right << setw(6) << duration.count() / 1000 << "мс │ ";
            }
        }
        cout << "\n";
    }
    cout << "└─────────────┴──────────┴──────────┴──────────┴──────────┴──────────┘\n";
}

// Демонстрация работы каждой сортировки
void demonstrateSorts() {
    cout << "\n\n╔════════════════════════════════════════════════════════════╗\n";
    cout << "║           ДЕМОНСТРАЦИЯ РАБОТЫ АЛГОРИТМОВ                 ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    vector<int> arr = {64, 34, 25, 12, 22, 11, 90, 5, 77, 30, 18, 42};
    
    cout << "\nИсходный массив: ";
    Sorting::printArray(arr);
    cout << "\n";
    
    vector<pair<string, void(*)(vector<int>&)>> sorts = {
        {"Пузырьком", Sorting::bubbleSort},
        {"Вставкой", Sorting::insertionSort},
        {"Выбором", Sorting::selectionSort},
        {"Шелла", Sorting::shellSort},
        {"Слиянием", Sorting::mergeSort},
        {"Быстрая", Sorting::quickSort},
        {"Пирамид.", Sorting::heapSort},
        {"Подсчётом", Sorting::countingSort}
    };
    
    for (const auto& sortPair : sorts) {
        vector<int> temp = arr;
        sortPair.second(temp);
        cout << left << setw(12) << sortPair.first << ": ";
        Sorting::printArray(temp);
    }
}

// Главная функция
int main() {
    setlocale(LC_ALL, "Russian");
    
    cout << "╔════════════════════════════════════════════════════════════╗\n";
    cout << "║             МОДУЛЬ СОРТИРОВКИ v1.0                       ║\n";
    cout << "║             8 алгоритмов сортировки                      ║\n";
    cout << "╚════════════════════════════════════════════════════════════╝\n";
    
    // Генерируем случайный массив
    vector<int> testArray = Sorting::generateRandomArray(200, 0, 1000);
    
    // Запускаем все тесты
    testAllSorts(testArray);
    performanceTest();
    demonstrateSorts();
    
    cout << "\n\n════════════════════════════════════════════════════════════\n";
    cout << "Тестирование завершено!" << endl;
    
    return 0;
}