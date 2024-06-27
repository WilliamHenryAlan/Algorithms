#include <iostream>
#include <vector>
#include <functional>
using namespace std;

/*
 Method1: backtrack
每一个node都是子集
*/
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtracking(nums,0);
        return ans;
    }
    void backtracking(vector<int>& nums,int start) {
        ans.push_back(path);
        for (int i = start;i < nums.size();i++) {
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
};

/*
2024.6.27
*/
//从答案的视角考虑 选哪个
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //创建返回值为void 接受一个int传参的函数对象dfs
        //lambda expression [&]表示全局引用捕获 
        vector<int> path;
        vector<vector<int>> ans;
        function<void(int)> dfs = [&](int start){ 
            ans.push_back(path);
        /*
        start表示当前递归调用中需要考虑的子集元素的起始索引。
        它确保在每次递归调用中，只考虑尚未包含在当前子集中的元素，从而避免重复生成相同的子集。
        */
        /*
        i是当前循环中的索引变量，用于遍历从start到数组末尾的元素，并选择其中的一个元素加入当前子集。
        */
            for (int i = start;i < nums.size();i++) {
                path.push_back(nums[i]);
                dfs(i + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
//选或者不选
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        //创建返回值为void 接受一个int传参的函数对象dfs
        //lambda expression [&]表示全局引用捕获 
        function<void(int)> dfs = [&](int start){ 
        if (start == nums.size()) {
            ans.push_back(path);
            return;
        }
        path.push_back(nums[start]);
        dfs(start + 1);
        path.pop_back();
        dfs(start + 1);
        };
        dfs(0);
        return ans;
    }
};

