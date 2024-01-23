/*
Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0

*/
#include <iostream>
#include <vector>
class Solution {
    public:
        int minSubArrayLen(int target,std::vector<int>& nums) {
            if (nums[0]==target) return 1;
            int begin=0,end=0;
            int sum = 0,len = nums.size()+1,ret=len;
            while (end<nums.size())
            {
                sum += nums[end];
                while (sum>=target)
                {
                    len=end-begin+1;
                    if (len <= ret) ret=len;
                    sum  -= nums[begin];
                    begin++;
                }   
                end++;
            }
            if (len == nums.size()+1) return 0;
            return ret;
        }
};
int main()
{
    std::vector<int> nums;
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);
    nums.push_back(3);
    Solution t;
    std::cout << t.minSubArrayLen(7,nums) << std::endl;
}