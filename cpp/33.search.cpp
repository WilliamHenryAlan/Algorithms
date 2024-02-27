#include <iostream>
#include <vector>
using namespace std;

/*
3,4,5,6,1,2

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) return nums[0] == target ? 0 : -1;
        //第一次二分查找旋转点
        int l = 0,r = n - 1;
        while () {
            int m = l + (r - l) / 2;
            if ()
        }
    }
};