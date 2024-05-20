#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = 0;
        for (const int &num:nums) {
            if (len < 2 || nums[len - 2] != num) {
                nums[len++] = num;
            }
        }
        return len;
    }
};

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        int slow = 2,fast = 2;
        for (;fast < nums.size();++fast) {
            if (nums[fast] != nums[slow - 2]) nums[slow++] = nums[fast];
        }
        return slow;
    }
};