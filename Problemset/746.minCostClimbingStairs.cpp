#include <iostream>
#include <vector>
using namespace std;
/*
Method: dp
1.明确题意
    1:从0开始跳花费体力吗？
    是不花费的
    2.顶楼在哪里？
    eg:nums = [10,15,20] 到达20是不花费的 从20开始跳是花费的
2.dp[i]为到达index = i层的最低花费
3.dp[0] = 0,dp[1] = 0 
4.dp[i] = std::min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
5.从前往后遍历
6.根据题意 题目要求到达index = nums.size()层的最小花费
*/
class Solution {
public:
    /*
    10,15,20
    0,1,2
    */
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n < 2) return 0;
        vector<int> dp(n+1,0);
        for (int i = 2;i <= n;i++) {
            dp[i] = std::min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);
        }
        return dp[n];
    }
};

/*
review 2024.5.23
*/
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        if (cost.size() < 2) return 0;
        int n = cost.size();
        vector<int> dp(n + 1,0);
        for (int i = 2;i <= n;i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1],dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};