
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ret = 0;//每次取最大的子数组长度
        int l = 0, r = 0;//定于左右指针
        for (; r < nums.size(); r++) {
            if (nums[r] == 0) k--;//默认左右指针都为0 第一个元素已经在窗口中了 所以先判断 nums[r] == 0
            /*
            循环条件是 k < 0 而不是k == 0 
            因为当用尽最后一次反转机会时 k = 0 但是此时的滑动窗口仍然有效的
            如果是k == 0的条件 当用尽最后一次反转机会时 将会进入这个循环 被迫移动left
            */
            while (k < 0) if (nums[l++] == 0) k++;
            ret = max(ret, r - l + 1);  // r - l + 1求取长度
        }
        return ret;
    }
};
/*
2024.7.8
*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        for (int l = 0,r = 0;r < nums.size();r++) {
            if (nums[r] == 0) k--;
            while (k < 0) if (nums[l++] == 0) k++;
            ans = max(ans,r - l + 1);
        }
        return ans;
    }
};