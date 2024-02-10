#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int sum = 0;
        std::function<void(int,int)> dfs = [&](int start,int target) {
            if (sum > target) return;
            if (sum == target) {
                ans.push_back(path);
                return;
            }
            for (;start < candidates.size();start++) {
                path.push_back(candidates[start]);
                sum += candidates[start];
                dfs(start,target);
                sum -= candidates[start];
                path.pop_back();
            }
        };
        dfs(0,target);
        return ans;
    }
};