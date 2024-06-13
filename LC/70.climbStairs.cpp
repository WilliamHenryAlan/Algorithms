#include <iostream>
#include <vector>
using namespace std;
/*
dynamic programming
1.dp[i]表示爬到i阶台阶有dp[i]种方法
2.dp[i] = dp[i-1]+dp[i-2]
3.初始化dp[0] = 1 dp[1] = 2
4.确定遍历顺序:从前向后
5.打印dp数组 debug
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;
        vector<int> dp(n+1,0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3;i <= n;i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

/*
review 2024.5.23
*/
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        vector<int> dp(n);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2;i < n;i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n - 1];
    }
};