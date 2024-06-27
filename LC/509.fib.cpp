#include <iostream>
using namespace std;
/*
一共四种方法层层递进
1.直接递归 但是时间复杂度为O(2^n)
2.用hashtable进行保存计算结果 二叉树为二叉链表 时间复杂度为O(n) 但是需要额外的空间
3.去掉递的过程 预处理前两个元素 进行推
4.空间优化 进行状态压缩

*/
//会产生很多冗余计算
class Solution {
public:
    int fib(int n) {
        if (n < 2) return n;
        else return fib(n-1)+fib(n-2);
    }
};
//用cache存储算过的fib(n)
class Solution {
public:
    unordered_map<int,int> cache;
    int fib(int n) {
        if (n < 2) return n;
        if (cache.find(n) != cache.end()) {
            return cache[n];
        }else {
            return cache[n] = fib(n-1)+fib(n-2);
        }
    }
};
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

