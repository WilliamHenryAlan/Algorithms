
#include <iostream>
#include <vector>
using namespace std;
/*
dp:
1.观察可得:
node数量为0 => 1
node数量为1 => 1
node数量为2 => 2

2.如果n[i]为nodeRoot 左侧有10种二叉树形态 右侧5种二叉树形态  => 一共是10 * 5 = 50种
            root
           /    \
10种二叉树形态    5种二叉树形态  => 一共是10 * 5 = 50种

3.
node数量为3 => 
dp[3] = dp[0]*dp[2] + dp[1]*dp[3] + dp[2]


*/

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1,0);
        dp[0] = 1;
        for (int i = 1;i <= n;i++) {        //递推到有n个node
            for (int j = 1;j <= i;j++) {
                dp[i] += dp[j-1] * dp[i-j];     //是累加的
            }
        }
        return dp[n];
    }
};