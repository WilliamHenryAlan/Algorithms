#include <iostream>
#include <vector>
using namespace std;
/*
dp[i][j]走到i,j共有几种不同走法
dp[i][j] = dp[i-1][j]+dp[i][j-1]
dp[0][0] = 1;
*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int> > dp(m,vector<int>(n));  
        for (int i = 0;i < m;i++) {
            dp[i][0] = 1;
        }
        for (int i = 0;i < n;i++) {
            dp[0][i] = 1;
        }
        if (m < 1 || n < 1) return dp[n-1][m-1];
        for (int i = 1;i < dp.size();i++) {
            for (int j = 1;j < dp[i].size();j++) {
                dp[i][j] = dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};