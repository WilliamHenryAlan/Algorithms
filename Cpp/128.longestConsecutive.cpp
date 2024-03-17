#include<iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        //去重 题目可以出现重复元素 eg: [0, 1, 1, 2]最长为3
        unordered_set<int> myset(nums.begin(),nums.end());
        vector<int> temp(myset.begin(),myset.end());
        nums = temp;
        //先排序
        sort(nums.begin(),nums.end());
        int ans = 1;
        int i = 0,j = 0;
        while (j < nums.size() - 1) {
            //保证不越界
            while (j < nums.size() - 1 && nums[j + 1] - 1 == nums[j]) j++;
            //右 - 左 + 1计算长度
            ans = max(j - i + 1,ans);
            j++;
            i = j;
        }
        return ans;
    }
};
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> myset(nums.begin(),nums.end());
        int ret = 0;
        for (auto elem:myset) {
            int temp = elem;
            if (myset.find(temp + 1) == myset.end()) {
                while (myset.find(temp - 1) != myset.end()) {
                    temp--;
                }
            }
            ret = max(elem - temp + 1,ret);
        }
        return ret;
    }
};