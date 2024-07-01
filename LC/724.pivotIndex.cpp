#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

/*
Method 1:
*/
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int l = 0;
        int r = accumulate(nums.begin(),nums.end(),0);
        for (int i = 0;i < nums.size();i++) {
            r -= nums[i];   //第一次进入loop 此时r为所有的总和 l为0 所以先r -= nums[i]或者可以先l += nums[j];
            if (l == r) return i;   
            l += nums[i];
        }
        return -1;
    }
};
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int j = 0;
        int l = 0,r = accumulate(nums.begin(),nums.end(),0);
        for (;j < nums.size();j++) {
            l += nums[j];
            if (l == r) return j;
            r -= nums[j];
        }
        return -1;
    }
};

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


