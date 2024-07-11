/*
同1004题一样的思路
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int k = 1;
        for (int l = 0,r = 0;r < nums.size();r++) {
            if (nums[r] == 0) k--;//默认左右指针都为0 第一个元素已经在窗口中了 所以先判断 nums[r] == 0
            /*
            循环条件是 k < 0 而不是k == 0 
            因为当删除一个元素时 k = 0 但是此时的滑动窗口仍然有效的
            如果是k == 0的条件 当当删除一个元素时 将会进入这个循环 被迫移动left
            */
            while (k < 0) {
                if (nums[l++] == 0) k++;
            }
            ans = max(ans,r - l + 1);
        }
        return ans - 1;//必须删除一个元素
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0,r = 0,ans = 0,k = 1;
        for (;r < nums.size();r++) {
            if (nums[r] == 0) k--;
            while (k < 0) {
                if (nums[l++] == 0) k++;
            }
            ans = max(ans,r - l + 1);
        }
        return ans - 1;
    }
};