/**
 * 2023.12.22
 * 
 * solution:
 * 
*/
#include <iostream>
#include <vector>
using namespace std;
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