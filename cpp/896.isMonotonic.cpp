#include <iostream>
#include <vector>
#include <set>
using namespace std;
//一次遍历
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return true;
        bool inc = true,dec = true;
        for (int i = 0;i < len - 1;i++) {
            if (nums[i] > nums[i + 1]) inc = false;
            if (nums[i] < nums[i + 1]) dec = false;
        }
        return inc || dec;
    }
};
//二次遍历 也可以用c+内置函数is_sorted()
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int len = nums.size();
        if (len == 1) return true;
        return increase(nums) || decrease(nums);
    }
    bool increase(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0;i < len - 1;i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        return true;
    }
    bool decrease(vector<int>& nums) {
        int len = nums.size();
        for (int i = 0;i < len - 1;i++) {
            if (nums[i] < nums[i + 1]) return false;
        }
        return true;
    }
};