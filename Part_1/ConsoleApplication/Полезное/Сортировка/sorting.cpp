#include "sorting.h"
#include <random>
#include <chrono>

using namespace std;

// ===================== 1. СОРТИРОВКА ПУЗЫРЬКОМ =====================
void Sorting::bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// ===================== 2. СОРТИРОВКА ВСТАВКОЙ =====================
void Sorting::insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// ===================== 3. СОРТИРОВКА СЛИЯНИЕМ =====================
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    vector<int> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortRecursive(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    mergeSortRecursive(arr, left, mid);
    mergeSortRecursive(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void Sorting::mergeSort(vector<int>& arr) {
    mergeSortRecursive(arr, 0, arr.size() - 1);
}

// ===================== 4. БЫСТРАЯ СОРТИРОВКА =====================
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

int partitionMedian(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;
    if (arr[mid] < arr[low]) swap(arr[mid], arr[low]);
    if (arr[high] < arr[low]) swap(arr[high], arr[low]);
    if (arr[high] < arr[mid]) swap(arr[high], arr[mid]);
    swap(arr[mid], arr[high]);
    return partition(arr, low, high);
}

void quickSortRecursive(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partitionMedian(arr, low, high);
        quickSortRecursive(arr, low, pi - 1);
        quickSortRecursive(arr, pi + 1, high);
    }
}

void Sorting::quickSort(vector<int>& arr) {
    quickSortRecursive(arr, 0, arr.size() - 1);
}

// ===================== 5. СОРТИРОВКА ПОДСЧЁТОМ =====================
void Sorting::countingSort(vector<int>& arr) {
    if (arr.empty()) return;
    
    int min_val = *min_element(arr.begin(), arr.end());
    int max_val = *max_element(arr.begin(), arr.end());
    int range = max_val - min_val + 1;
    
    vector<int> count(range, 0);
    
    for (int num : arr) {
        count[num - min_val]++;
    }
    
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }
    
    vector<int> output(arr.size());
    
    for (int i = arr.size() - 1; i >= 0; i--) {
        int num = arr[i];
        count[num - min_val]--;
        output[count[num - min_val]] = num;
    }
    
    arr = output;
}

// ===================== 6. СОРТИРОВКА ВЫБОРОМ =====================
void Sorting::selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
        }
    }
}

// ===================== 7. СОРТИРОВКА ШЕЛЛА =====================
void Sorting::shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// ===================== 8. ПИРАМИДАЛЬНАЯ СОРТИРОВКА =====================
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    
    if (left < n && arr[left] > arr[largest])
        largest = left;
    
    if (right < n && arr[right] > arr[largest])
        largest = right;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void Sorting::heapSort(vector<int>& arr) {
    int n = arr.size();
    
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

// ===================== УТИЛИТЫ =====================
void Sorting::printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

bool Sorting::isSorted(const vector<int>& arr) {
    for (size_t i = 1; i < arr.size(); i++) {
        if (arr[i] < arr[i - 1]) return false;
    }
    return true;
}

vector<int> Sorting::generateRandomArray(int size, int minVal, int maxVal) {
    vector<int> arr(size);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(minVal, maxVal);
    
    for (int i = 0; i < size; i++) {
        arr[i] = dis(gen);
    }
    return arr;
}

void Sorting::copyArray(const vector<int>& src, vector<int>& dest) {
    dest = src;
}