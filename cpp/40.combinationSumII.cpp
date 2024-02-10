
#include <iostream>
#include <vector>
using namespace std;

/*
list中存在重复元素的 组合问题

*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int sum = 0;
        vector<int> path;
        vector<bool> used(candidates.size(),false);
        vector<vector<int>> ans;
        backtracking(candidates,target,sum,0,path,used,ans);
        return ans;
    }
    void backtracking(vector<int>& candidates,
                        int target,
                        int& sum,
                        int start,
                        vector<int>& path,
                        vector<bool>& used,
                        vector<vector<int>>& ans
                        ) {
        if (sum > target) {
            return ;
        }
        if (sum == target) {
            ans.push_back(path);
            return ;
        }
        // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
        // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
        // 要对同一树层使用过的元素进行跳过
        for (;start < candidates.size();start++) {
            if (start != 0 && candidates[start] == candidates[start-1] && used[start] == false) {
                continue ;
            }
            path.push_back(candidates[start]);
            sum += candidates[start];
            used[start] = true;
            backtracking(candidates,target,sum,start,path,used,ans);
            sum -= candidates[start];
            used[start] = false;
            path.pop_back();
        }
    }
};