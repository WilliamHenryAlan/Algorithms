
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
                ans.push_back(nums[i]);//进入node要添加元素
                isUsed[i] = true;
                backtracking(nums,n);
                ans.pop_back(); //离开node时要恢复上一个状态
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
/*
review 2024.6.27
*/
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        vector<vector<int>> ans;
        vector<bool> isUsed;
        function<void(int start)> dfs = [&](int start) {
            int n = nums.size();
            isUsed.resize(n,false);
            if (track.size() == n) {
                ans.push_back(track);
                return ;
            }
            for (int i = 0;i < n;i++) {
                if (!isUsed[i]) {
                    isUsed[i] = true;
                    track.push_back(nums[i]);
                    dfs(i + 1);
                    track.pop_back();
                    isUsed[i] = false;
                }
            }
        };
        dfs(0);
        return ans;
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