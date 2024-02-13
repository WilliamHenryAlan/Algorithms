
#include <iostream>
#include <vector>

using namespace std;
/*
Method 1:prefixSum
前缀和嵌套两层for循环求sum == k的子数组 cnt++
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n+1,0);
        for (int i = 1;i <= n;i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        int cnt = 0;
        for (int i = 0;i < n;i++) {
            for (int j = i;j < n;j++) {
                if (prefix[j+1] - prefix[i] == k) cnt++;
            }
        }
        return cnt;
    }
};
/*

*/