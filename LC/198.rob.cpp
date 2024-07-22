#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0],nums[1]);
        for (int i = 2;i < nums.size();i++) {
            dp[i] = max(dp[i - 1],dp[i - 2] + nums[i]);
        }
        return dp[n - 1];
    }
};
/*
2024.7.22
记忆化搜索
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        unordered_map<int,int> cache;
        int ans = 0;
        function<int(int)> dfs = [&](int n) -> int{
            if (n < 0) {
                return 0;
            }
            if (cache.contains(n)) return cache[n];
            ans = max(dfs(n - 1),dfs(n - 2) + nums[n]);
            cache[n] = ans;
            return ans;
        };
        return dfs(nums.size() - 1);
    }
};