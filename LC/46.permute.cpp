
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    vector<int> ans;
    vector<vector<int>> ret;
    vector<bool> isUsed;
public:
    void backtracking (vector<int>& nums,int n) {
        if (ans.size() == n) {
            ret.push_back(ans);
            return ;
        }
        for (int i = 0;i < n;++i) {
            if (isUsed[i] == false) {
                ans.push_back(nums[i]);
                isUsed[i] = true;
                backtracking(nums,n);
                ans.pop_back();
                isUsed[i] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        isUsed.resize(n,false);
        backtracking(nums,n);
        return ret;
    }
};

// class Solution {
// public:
//     vector<vector<int>> permute(vector<int>& nums) {
//         vector<int> path;
//         vector<vector<int>> res;
//         int len = nums.size();
//         if (len == 0) return res;
//         vector<bool> used(len,false);
//         backtracking(nums,used,path,res);
//         return res;
//     }   
//     void backtracking(vector<int>& nums,
//                         vector<bool>& used,
//                         vector<int>& path,
//                         vector<vector<int>>& res) {
//         //到leafNode        
//         if (path.size() == nums.size()) {
//             res.push_back(path);
//             return;
//         }

//         for (int i = 0;i < nums.size();i++) {
//             if (!used[i]) {
//                 path.push_back(nums[i]);
//                 used[i] = true;
//                 backtracking(nums,used,path,res);
//                 //进行回溯
//                 used[i] = false;
//                 path.pop_back();
//             }
//         }
//     }
// };