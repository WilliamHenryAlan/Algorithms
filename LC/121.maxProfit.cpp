
#include <iostream>
#include <vector>

using namespace std;
1.确认dp数组含义 要二维dp才能表示两种状态 dp[i][1]表示持有最大值 dp[i][0]表示不持有最大值

2.确认状态转移方程

     dp[i][1] = max(dp[i - 1][1],-prices[i]); //从 上个状态持有 和 没买股票买了之后持有 中选最大值

      dp[i][0] = max(dp[i - 1][0],dp[i - 1][1] + prices[i]); //从 上个状态未持有 和 卖出之后未持有 中选择最大值

3.初始化 未持有为0 持有则减去对应的prices[i]

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1,vector<int>(2));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1;i < prices.size();i++) {
            dp[i][0] = max(dp[i - 1][0],-prices[i]);
            dp[i][1] = max(dp[i - 1][1],dp[i - 1][0] + prices[i]);
        } 
        return max(dp[n - 1][1],dp[n - 1][0]);
    }
};