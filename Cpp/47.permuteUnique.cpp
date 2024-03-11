#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
/*
全排列1给定数组无重复元素与 
全排列1相比 区别在于去重
重复主要是出现在横向 排序之后通过 used去重 
和组合问题中nums是否有重复元素去重方式一致
*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return res;
        sort(nums.begin(),nums.end());  //重复主要是出现在横向 排序之后通过 used去重
        vector<bool> used(len,false);
        backtracking(nums,used,path,res);
        return res;
    }   
    void backtracking(vector<int>& nums,
                        vector<bool>& used,
                        vector<int>& path,
                        vector<vector<int>>& res) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0;i < nums.size();i++) {
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;  //注意数组越界问题 值相等 并且上一个相同元素没有被使用
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums,used,path,res);
                //进行回溯
                used[i] = false;
                path.pop_back();
            }
        }
    }
};