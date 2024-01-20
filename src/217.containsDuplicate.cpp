/*
题目要求给定array 如果有重复元素 return true/false
法1:先进行快quicksort 比对相邻元素是否相同
*/
#include <iostream>
#include <vector>
#include <unordered_set>
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        for (int i = 1;i < nums.size();++i) {
            if (nums[i-1] == nums[i]) return true;
        }
        return false;
    }
};


//法2:哈希表查找是否存在
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> set;
        for (int& i:nums) {
            if (set.find(i) == set.end()) {
                set.insert(i);
            }else {
                return true;
            }
        }
        return false;
    }
};