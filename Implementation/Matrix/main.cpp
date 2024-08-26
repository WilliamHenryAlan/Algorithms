#include <iostream>
#include <vector>
#include <chrono>

int main() {
    const int rows = 10000;
    const int cols = 10000;
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 1));

    // 行优先遍历
    auto start = std::chrono::high_resolution_clock::now();
    long long sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum += matrix[i][j];
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Row-major traversal time: " << elapsed.count() << " seconds\n";

    // 列优先遍历
    start = std::chrono::high_resolution_clock::now();
    sum = 0;
    for (int j = 0; j < cols; j++) {
        for (int i = 0; i < rows; i++) {
            sum += matrix[i][j];
        }
    }
    end = std::chrono::high_resolution_clock::now();
    elapsed = end - start;
    std::cout << "Column-major traversal time: " << elapsed.count() << " seconds\n";

    return 0;
}

