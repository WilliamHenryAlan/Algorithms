#include <iostream>
#include <vector>
using namespace std;
void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

int main() {
    vector<int> arr{1, 7, 3, 6, 5, 6};
    print(arr);
    int n = arr.size();
    vector<int> prefixSum(n+1,0);
    for (int i = 1;i <= n;i++) {
        prefixSum[i] = prefixSum[i-1] + arr[i-1]; 
    }
    print(prefixSum);
    cout << "[2,3]" << prefixSum[4] - prefixSum[2] << endl;
}