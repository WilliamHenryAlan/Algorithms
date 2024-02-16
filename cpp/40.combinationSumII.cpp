
#include <iostream>
#include <vector>
using namespace std;
/*
组合问题 
每个数取一次 有重复元素 取sum == target
1.sort()
2.
*/
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    int sum = 0;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<bool> used(nums.size(),false);
        dfs(nums,target,0,used);
        return ans;
    }
    void dfs(vector<int>& nums,int target,int start,vector<bool>& used) {
        if (sum > target) return ;
        if (sum == target) {
            ans.push_back(path);
            return ;
        }

        for (int i = start;i < nums.size();i++) {
            if (i > 0 && nums[i] == nums[i-1]&& used[i-1] == false) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            sum += nums[i];
            dfs(nums,target,i+1,used);
            path.pop_back();
            used[i] = false;
            sum -= nums[i];
        }
    }
};
