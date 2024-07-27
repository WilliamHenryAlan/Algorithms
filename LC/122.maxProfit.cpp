#include <iostream>
#include <vector>
using namespace std;
/*
greedy
1.可以算出每天的profit 累加所有的正数
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        for (int i = 1;i < prices.size();i++) 
            res += max(prices[i] - prices[i-1],0);
        return res;
    }
};


//dp[i][1]表示持有最大值 dp[i][0]表示不持有最大值
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] =-prices[0];
        for (int i = 1;i < n;i++) {
            dp[i][1] = max(dp[i - 1][1],dp[i - 1][0] - prices[i]);
            dp[i][0] = max(dp[i - 1][0],dp[i - 1][1] + prices[i]);
        } 
        return max(dp[n - 1][0],dp[n - 1][1]);
    }
};