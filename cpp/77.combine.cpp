
#include <iostream>
#include <vector>
using namespace std;

/*
review 2024.1.29
1.举例给定 n = 4 则[1,2,3,4]可能的情况：
         1            2       3       4
  1,2   1,3   1,4    2,3    2,4  3,4      --
2.
*/
class Solution {
public:
    void backtracking(int startIndex,int n,int k,vector<int>& path,vector<vector<int>>& ret) {
        //写循环终止条件 也就是leafNode 当path元素个数为k时 得到答案
        if (path.size() == k) {
            ret.emplace_back(path);
            return;
        }
        for (int i = startIndex;i <= n;++i) {
            //每次push进去 进行递归 开始应该是先把root为1的子树递归完[1,2],[1,3][1,4] [2,3]……
            path.emplace_back(i);
            backtracking(i+1,n,k,path,ret);
            //回溯 比如[1,2]暂存之后 要把2进行pop 才能有[1,3]
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> ret;
        backtracking(1,n,k,path,ret);
        return ret;
    }
};

/**
 * 2023.12.22 
*/
class Solution {
public:
    void backTracking(std::vector<int>& path,std::vector<std::vector<int>>& ret,int n,int k,int startIndex) {
        if (path.size() == k) {     //回溯算法递归终止条件 当path的元素达到k个 也就是到leafnode时 递归结束
            ret.push_back(path);
            return ;
        }
        for (int i = startIndex;i < n;i++) {
            path.push_back(i);
            backTracking(path,ret,n,k,i+1);
            path.pop_back();       //回溯
        }
    }
    vector<vector<int>> combine(int n, int k) {
        std::vector<int> path;
        std::vector<std::vector<int>> ret;
        backTracking(path,ret,n+1,k,1);
        return ret;
    }
};