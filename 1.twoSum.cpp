/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]

*/
/*
solution:
1.因为要找元素 想到用hash table解决 需要下标和元素 用unordered_map解决
2.遍历数组 如果没找到 就把元素放进map中 找到了返回value 并把nums清空 放进value和i
    因为需要比对的是数组里面的数值 但是返回我们需要的下标 所以把key设置为数组元素的数值 value设置为下标
*/
#include <iostream>
#include <vector>
#include <unordered_map>
std::vector<int> twoSum(std::vector<int>& nums,int target) {
    int len = nums.size();
    std::unordered_map<int,int> nums_map;
    for (int i = 0; i < len; i++)
    {
        auto iter = nums_map.find(target-nums[i]);
        if ( iter!= nums_map.end()) {
            return {iter->second,i};    //implicit 可以写成explicit return std::vector<int>{iter->second,i};
        }
        else {
            nums_map.insert(std::pair<int,int>(nums[i],i));
        }
    }
    return {};
}
