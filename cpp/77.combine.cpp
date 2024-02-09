
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> dfs = [&](int i) {
            int d = k - path.size(); // 还要选 d 个数
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            for (int j = i; j >= d; --j) {
                path.push_back(j);
                dfs(j - 1);
                path.pop_back();
            }
        };
        dfs(n);
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> path;
        function<void(int)> dfs = [&](int i) {
            int d = k - path.size(); // 还要选 d 个数
            if (d == 0) {
                ans.emplace_back(path);
                return;
            }
            // 不选 i
            if (i > d) dfs(i - 1);
            // 选 i
            path.push_back(i);
            dfs(i - 1);
            path.pop_back();
        };
        dfs(n);
        return ans;
    }
};

/*
review 2024.1.29
1.举例给定 n = 4 k = 3 则[1,2,3,4]可能的情况：
1 -> 1,2 -> 1,2,3  path.size() == 3收获结果
            1,2,4 
     1,3 -> 1,3,4
2 -> 2,3 -> 2,3,4
*/
class Solution {
public:
    void backtracking(int startIndex,int n,int k,vector<int>& path,vector<vector<int>>& ret) {
        //写循环终止条件 也就是leafNode 当path元素个数为k时 得到答案
        if (path.size() == k) {
            ret.emplace_back(path);
            return;
        }
        for (int i = startIndex;i <= n - (k - path.size()) + 1;++i) {
            //决策 是否要这个元素
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
/*
剪枝操作
1.path.size()表示现在有多少个elements
2.需要k个元素 还差 k - path.size()个elements
3.还剩n - i个元素 n - i >= k - path.size()
4.eg: n = 4 ,k = 3
需要1～4个数字做size = 3的排列
至少要从2开始遍历 才满足有size = 3
n - (k - path.size()) >= i
4 - (3 - 0)  + 1 >= 2 
n - (k - path.size()) + 1 >= i

for (int i = startIndex;i <= n - (k - path.size()) + 1;++i)

*/

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

/*
review 2024.2.7
*/
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> res;
        backtracking(1,n,k,path,res);
        return res;
    }

    void backtracking(int startIndex,int n,int k,vector<int>& path,vector<vector<int>>& res) {
        if (path.size() == k) {
            res.push_back(path);
            return;
        }

        for (;startIndex <= n;startIndex++) {
            path.push_back(startIndex);
            backtracking(startIndex+1,n,k,path,res);
            path.pop_back();
        }
    }
};