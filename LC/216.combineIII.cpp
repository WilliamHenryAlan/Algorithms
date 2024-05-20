#include <iostream>
#include <vector>
using namespace std;

/*
review 2024.2.13

*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k,n,1,0);
        return res;
    }
    void dfs(int k,int n,int start,int sum) {
        if (path.size() > k) return;    //进行剪枝 当path.size() > 要求的k个数就不需要继续递归了 return即可
        if (path.size() == k && sum == n) { 
            res.push_back(path);
            return ;
        }
        for (int i = start;i <= 9;i++) {
            path.push_back(i);
            sum += i;
            dfs(k,n,i+1,sum);
            path.pop_back();
            sum -= i;
        }
    }
};


class Solution {
public:
    void backtracking(int startIndex,   //combine无序 把1存在的都遍历完再遍历 2..3..4...
                      int k,int n,int sum,  //sum为当前path的和     k为元素达到k个则结束    n为目标和
                      vector<int>& path,
                      vector<vector<int>>& ans) {
        if (path.size() == k && sum == n) {     ////1～9组合 组合元素达到k && 组合的和等于n
            ans.push_back(path);
            return;
        }

        for (int i = startIndex;i <= 9;++i) {
            sum += i;
            path.push_back(i);
            backtracking(i+1,k,n,sum,path,ans);
            //回溯
            sum -= i;   
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int startIndex = 1;
        int sum = 0;
        vector<int> path;
        vector<vector<int>> ans;
        backtracking(startIndex,k,n,sum,path,ans);
        return ans;
    }
};
