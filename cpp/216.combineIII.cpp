#include <iostream>
#include <vector>
using namespace std;

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


class Solution {
public:
    void backtracking(int startIndex,   //combine无序 startIndex用于去重 把1存在的都遍历完再遍历 2..3..4...
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