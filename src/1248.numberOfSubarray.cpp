#include <iostream>
#include <vector>
using namespace std;

/*
Method 1:prefix Sum 前缀和
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return 0;
    }
};

std::vector<int> calculatePrefixSum(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> prefixSum(n);

    // 初始化前缀和数组的第一个元素
    prefixSum[0] = nums[0];

    // 计算前缀和数组的其他位置的值
    for (int i = 1; i < n; i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    return prefixSum;
}

int getRangeSum(const std::vector<int>& prefixSum, int start, int end) {
    if (start == 0) {
        return prefixSum[end];
    } else {
        return prefixSum[end] - prefixSum[start - 1];
    }
}

int main() {
    std::vector<int> nums = {1, 3, 2, 4, 5};

    // 计算前缀和数组
    std::vector<int> prefixSum = calculatePrefixSum(nums);

    // 查询区间和
    int start = 0;
    int end = 3;
    int rangeSum = getRangeSum(prefixSum, start, end);

    std::cout << "Sum of elements in range [" << start
              << ", " << end << "] is: " << rangeSum << std::endl;

    return 0;
}
