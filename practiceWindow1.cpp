#include <iostream>
#include <cstdlib>

// 交换两个元素的值
void swap(void* a, void* b, size_t size) {
    char* p = static_cast<char*>(a);
    char* q = static_cast<char*>(b);
    while (size--) {
        char tmp = *p;
        *p++ = *q;
        *q++ = tmp;
    }
}

// 分区函数，将小于等于基准值的元素放在左侧，大于基准值的元素放在右侧
int partition(void* arr, int low, int high, size_t size, int (*compare)(const void*, const void*)) {
    char* pivot = static_cast<char*>(arr) + high * size;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        char* current = static_cast<char*>(arr) + j * size;
        if (compare(current, pivot) <= 0) {
            i++;
            swap(static_cast<char*>(arr) + i * size, current, size);
        }
    }

    swap(static_cast<char*>(arr) + (i + 1) * size, pivot, size);
    return i + 1;
}

// 快速排序递归函数
void quickSort(void* arr, int low, int high, size_t size, int (*compare)(const void*, const void*)) {
    if (low < high) {
        int pivot = partition(arr, low, high, size, compare);
        quickSort(arr, low, pivot - 1, size, compare);
        quickSort(arr, pivot + 1, high, size, compare);
    }
}

// 快速排序的入口函数，对外提供的接口
void qsort(void* arr, size_t count, size_t size, int (*compare)(const void*, const void*)) {
    quickSort(arr, 0, count - 1, size, compare);
}

// 比较函数，用于指定排序规则
int compare(const void* a, const void* b) {
    int numA = *(reinterpret_cast<const int*>(a));
    int numB = *(reinterpret_cast<const int*>(b));

    if (numA < numB) return -1;
    if (numA > numB) return 1;
    return 0;
}

int main() {
    int arr[] = {5, 3, 8, 2, 1, 9, 4, 7, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, size, sizeof(int), compare);

    std::cout << "排序后的数组：";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}