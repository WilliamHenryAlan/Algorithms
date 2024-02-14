
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;  //起始index
        int n = nums.size();
        if (n == 1) return true;
        for (int i = 0;i <= cover;i++) {    // i <= cover 起始cover = 0 实现一次跳跃
            if (i == n-1) return true;     //当到达终点 return
            cover = max(nums[i]+i,cover);   //每次取能到达范围内的最大值
        }
        return false;
    }
};