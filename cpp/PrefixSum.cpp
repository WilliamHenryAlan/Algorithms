/*
前缀和：
*/
#include <iostream>
#include <vector>
using namespace std;

class PrefixSum {
public:
    vector<int> preSum;
public:
    /*
    构造前缀和数组
    */
    PrefixSum(vector<int>& nums) {
        this->preSum.resize(nums.size() + 1,0);
        for (int i = 1;i <= nums.size();i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
    }
    /*
    左闭右闭求区间和
    */
    int section(int begin,int end) {
        return preSum[end + 1] - preSum[begin];
    }
};
void print(const std::vector<int>& vi);

int main() {
    vector<int> arr{1, 7, 3, 6, 5, 6};
    print(arr);
    PrefixSum prefixSumArray(arr);
    print(prefixSumArray.preSum);
    cout << "[2,3] = " << prefixSumArray.section(2,3) << endl;
}
void print(const std::vector<int>& vi) {
    std::cout << "array: ";
    for (int element:vi) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}