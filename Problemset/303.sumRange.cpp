
#include <iostream>
#include <vector>
using namespace std;

/*
预处理前缀和数组:
        nums = [3, -1, 10]
        index   0   1   2
prefixSum = [0, 3, 2, 12]       
index        0  1  2  3
前缀和长度比nums多1 index为0多位置为0
这样区间可以为[0,2](左闭右闭)表示
nums数组index 0～2的元素的和为prefixSum[2+1] - prefixSump[0]
*/
class NumArray {
public:
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        int len = nums.size();
        prefix.resize(len+1);   //比给定的array长度+1
        prefix[0] = 0;
        for (int i = 1;i < prefix.size();i++) {
            prefix[i] = prefix[i-1] + nums[i-1]; //prefix[i]为[0,i]左闭右开区间和
        }
    }
    //求区间[left,right]左闭右闭区间
    int sumRange(int left, int right) {
        return prefix[right+1] - prefix[left];
    }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

/*
review 2024.5.29
class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size() + 1);
        for (int i = 1;i < prefixSum.size();++i) {
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right + 1] - prefixSum[left];
    }
};
*/