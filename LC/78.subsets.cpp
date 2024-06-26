#include <iostream>
#include <vector>
using namespace std;

/*
 Method1: backtrack
每一个node都是子集
*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return ans;
    }
    void backtracking(vector<int>& nums,int start) {
        ans.push_back(path);
        for (int i = start;i < nums.size();i++) {
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
};

