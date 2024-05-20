#include <iostream>
#include <vector>
using namespace std;

//记忆化搜索
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        function<int(int)> dfs = [&](int n) {
            if (n < 0) return 0;
            if (dp[n] != -1) return dp[n];
            dp[n] = max(dfs(n - 1),dfs(n - 2) + nums[n]);
            return dp[n];
        };
        return dfs(n - 1);
    }
};
//递推
int rob(vector<int>& nums) {
    if (nums.size() == 0) {
        return 0;
    }
    int N = nums.size();
    vector<int> dp(N+1, 0);
    dp[0] = 0;
    dp[1] = nums[0];
    for (int k = 2; k <= N; k++) {
        dp[k] = max(dp[k-1], nums[k-1] + dp[k-2]);
    }
    return dp[N];
}
//降低空间复杂度
int rob(vector<int>& nums) {
    int prev = 0;
    int curr = 0;
    for (int i : nums) {
        // 循环开始时，curr 表示 dp[k-1]，prev 表示 dp[k-2]
        // dp[k] = max{ dp[k-1], dp[k-2] + i }
        int temp = max(curr, prev + i);
        prev = curr;
        curr = temp;
        // 循环结束时，curr 表示 dp[k]，prev 表示 dp[k-1]
    }
    return curr;
}

