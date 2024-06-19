#include <iostream>
#include <stack>
#include <vector>
using namespace std;

/*
双指针 滑动窗口

*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;   //注意边界条件的处理 因为题目要求严格 < k 乘积至少是1 所以 <= 1 return 0
        int l = 0;
        int r = 0;
        int ans = 0;
        int multi = 1;
        while (r < nums.size()) {
            multi *= nums[r];
            while (multi >= k) {    //处理滑动窗口
                multi /= nums[l++];
            }
            ans += r - l + 1;       //子数组的数量
            r++;
        }
        return ans;
    }
};
/*
review 2024.6.19
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        int n = nums.size();
        int multiplication = 1;
        int ans = 0;
        for (int l = 0,r = 0;r < n;r++) {
            multiplication *= nums[r];
            /*
            右端点固定
            [l,r],[l+1,r],[l+2,r],[r,r]
            子数组个数为r - l + 1
            */
            while (multiplication >= k) { 
                multiplication /= nums[l];
                l++;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};