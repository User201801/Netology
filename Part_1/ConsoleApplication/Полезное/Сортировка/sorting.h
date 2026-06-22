#ifndef SORTING_H
#define SORTING_H

#include <vector>
#include <algorithm>
#include <iostream>

class Sorting {
public:
    // 1. Сортировка пузырьком
    static void bubbleSort(std::vector<int>& arr);
    
    // 2. Сортировка вставкой
    static void insertionSort(std::vector<int>& arr);
    
    // 3. Сортировка слиянием
    static void mergeSort(std::vector<int>& arr);
    
    // 4. Быстрая сортировка
    static void quickSort(std::vector<int>& arr);
    
    // 5. Сортировка подсчётом
    static void countingSort(std::vector<int>& arr);
    
    // 6. Сортировка выбором (дополнительно)
    static void selectionSort(std::vector<int>& arr);
    
    // 7. Сортировка Шелла (дополнительно)
    static void shellSort(std::vector<int>& arr);
    
    // 8. Пирамидальная сортировка (дополнительно)
    static void heapSort(std::vector<int>& arr);
    
    // Утилиты
    static void printArray(const std::vector<int>& arr);
    static bool isSorted(const std::vector<int>& arr);
    static std::vector<int> generateRandomArray(int size, int minVal = 0, int maxVal = 1000);
    static void copyArray(const std::vector<int>& src, std::vector<int>& dest);
};

#endif // SORTING_H