#include <iostream>
#include <vector>
using namespace std;

/*
example 1:
输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 


Method 1:prefix Sum 前缀和
1.  nums = [1,1,2,1,1]%2 => [1,1,0,1,1]
    对数组进行模2操作 奇数会得1 偶数得0
    这样把找k个奇数子数组转化为 
    
*/
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> prefixArr(len+1,0);
        for (int i = 0;i < len;i++) {
            prefixArr[i+1] = prefixArr[i]+nums[i]%2;
        }
        vector<int> hashtable;
        for ()
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
