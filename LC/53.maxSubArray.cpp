#include <iostream>
#include <vector>
using namespace std;
/*
暴力：
第一重for枚举左边界
第二重for枚举右边界
第三重for累加两边界数据和

O(n^3)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),ans = nums[0];
        for (int l = 0;l < n;l++) {
            for (int r = l + 1;r <= n;r++) {
                int sum = 0;
                for (int i = l;i < r;i++) {
                    sum += nums[i];
                    if (sum > ans) ans = sum;
                }
            }
        }
        return ans;
    }
};
/*
暴力：
用累加代替最后一个for循环

O(n^2)
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size(),ans = nums[0];
        for (int l = 0;l < n;l++) {
            int sum = 0;
            for (int r = l + 1;r <= n;r++) {
                sum += nums[r - 1];
                if (sum > ans) ans = sum;
            }
        }
        return ans;
    }
};

/*

*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0,ans = nums[0];
        int n = nums.size();
        for (int i = 0;i < n;i++) {
            if (sum < 0)
                sum = 0;
            sum += nums[i]; //枚举每一个数字为right bound sum为枚举当前数字为right bound时的最大子数组和
            ans = max(sum,ans);
        }
        return ans;
    }
};