
#include <iostream>
#include <vector>

using namespace std;
/*
Method 1:backtrack
和sebsets相比 重点在于去重
1.**先画树形结构** 可以发现 去重主要出现在同一层上 eg:[1,2,2] => [1,2] and [1,2]为同一个子集但是不同的2 导致重复 
2.因为start = 1时 遍历第一个2 结束之后进行回溯 再遍历第二个2导致重复
3.所以 可以用used数组记录 第一个2回溯之后2是false未使用的 && nums[i] == nums[i-1]
4.这样既可以避免[1,2,2]被剪枝 又可以去重

*/

class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());  //因为是子集组合类 所以是可以无序的 先进行排序 这样方便去重
        vector<bool> used(nums.size(),false);
        backtrack(nums,used,0);
        return res;
    }
    void backtrack(vector<int>& nums,vector<bool>& used,int start) {
        res.push_back(path);    //经过去重后的每一个node都是合法子集 包括[]
        for (int i = start;i < nums.size();i++) {
            if (i > 0 && nums[i] == nums[i-1] && used[i-1] == false) continue;  //i > 0 防止数组越界 对应2
            path.push_back(nums[i]);
            used[i] = true;     
            backtrack(nums,used,i+1);
            path.pop_back();
            used[i] = false;
        }
    }
};