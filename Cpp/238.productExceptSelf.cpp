#include <vector>
#include <iostream>
using namespace std;
/*
nums:       [1       2       3       4]
第一次遍历     1       1      1*2    1*2*3      ans[i]表示ans[0]到ans[i-1]的乘积
第二次遍历    2*3*4    3*4      4      1
ans         1*2*3*4  1*3*4   1*2*4  1*2*3*1
*/
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size(),1);     //初始化ans[0] = 1 防止数组越界
        int len = nums.size();
        for (int i = 1;i < len;i++) {       //计算当前元素左侧的乘积
            ans[i] = ans[i - 1] * nums[i - 1];
        }
        int temp = 1;
        for (int i = len - 2; i >= 0;i--) { //计算当前元素右侧的乘积+左侧
            temp *= nums[i + 1];
            ans[i] *= temp;
        }
        return ans;
    }
};