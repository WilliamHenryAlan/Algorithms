#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_set<vector<int>> hash;
        vector<int> path;
        vector<vector<int>> res;
        int len = nums.size();
        if (len == 0) return res;
        vector<bool> used(len,false);
        backtracking(nums,used,path,hash);
        for (auto& value:hash) {
            res.push_back(value);
        }
        return res;
    }   
    void backtracking(vector<int>& nums,
                        vector<bool>& used,
                        vector<int>& path,
                        unordered_set<vector<int>>& hash
                        ) {
        //到leafNode        
        if (path.size() == nums.size()) {
            hash.insert(path);
            return;
        }

        for (int i = 0;i < nums.size();i++) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                backtracking(nums,used,path,hash);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};