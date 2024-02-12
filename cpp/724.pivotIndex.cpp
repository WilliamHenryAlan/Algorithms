#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
Method 1:
tips:
要注意数组越界的情况
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l = 0;
        int r = accumulate(nums.begin(),nums.end(),0);
        for (int i = 0;i < nums.size();i++) {
            r -= nums[i];       //开始的时候 i = 0 先减去num[0]再判断 防止数组越界          
            if (l == r) return i;   
            l += nums[i];
        }
        return -1;
    }
};
/*
错误版本
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l = 0;
        int r = accumulate(nums.begin()+1,nums.end(),0);
        for (int i = 0;i < nums.size();i++) {
            if (l == r) return i;
            l += nums[i];
            r -= nums[i+1];             //数组越界
        }
        return -1;
    }
};
*/

/*
Method 2: prefixSum
prefixSum[j] = a0+a1+a2....a[j-1]
需要 a2~a4 区间的和 => prefix[4+1] - prefix[2] = a0+a1+...a4 - (a0+a1+...a1) = a2+a3+a4
求区间[i,j]和 = prefixSum[j+1] - prefixSum[i]
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n+1,0);
        for (int i = 1;i <= n;i++) {
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }
        for (int i = 0;i < n;i++) {
            if (prefixSum[i] == prefixSum[n] - prefixSum[i+1]) {
                return i;
            }
        }
        return -1;
    }
};



