
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cover = 0;  //起始index
        int n = nums.size();
        if (n == 1) return true;
        for (int i = 0;i <= cover;i++) {
            if (i == n-1) return true;
            cover = max(nums[i]+i,cover);
        }
        return false;
    }
};