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

/*
2024.7.19
1.枚举一个下标j >= i 并加入到path中
2.子问题 从下标 >= i中的数字构造子集
3.下一个子问题 从 >= j + 1 的数字中构造子集
*/

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        function<void(int)> dfs = [&](int i) {
            ans.push_back(path);//子集没有长度限制 每个都是答案
            if (n == i) return ;
            for (int j = i;j < n;j++) {
                path.push_back(nums[j]);
                dfs(j + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
/*
2024.7.19
1.枚举第i个数 是选还是不选
2.子问题 从 >=i 的数字中构造子集
3.下一个子问题 从 >= i + 1 的数字中构造子集
*/
class Solution {
public:
    vector<vector<int>> ans; 
    vector<int> path;
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        function<void(int)> dfs = [&](int i) {
            if (n == i) {
                ans.push_back(path);
                return ;
            }
            path.push_back(nums[i]);
            dfs(i + 1);
            path.pop_back();
            dfs(i + 1);
        };
        dfs(0);
        return ans;
    }
};

