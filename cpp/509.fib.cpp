#include <iostream>
using namespace std;

/*
dynamic programming:
1.确定dp数组的含义:第i项就是斐波那契数列的值
2.确定递推公式:F(n) = F(n-1)+F(n-2)
3.初始化dp数组:dp[0] = 1,dp[1] = 1;
4.确定遍历顺序:从前向后
5.打印dp数组 debug
*/
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        std::vector<int> dp(n+1,0);
        dp[1] = 1;
        for (int i = 2;i <= n;i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
//可以进行压缩
class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        int i = 0;
        int j = 1;
        int k = 0;
        for (int p = 2;p <= n;p++) {
            k = i+j;    
            i = j;
            j = k;
        }
        return j;
    }
};

//recursion
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        else return fib(n-1)+fib(n-2);
    }
};