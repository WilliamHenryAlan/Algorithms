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
#include <iostream>
#include <vector>
std::vector<int> twoSum(std::vector<int>& nums,int target)
{
    if (nums.size() == 0) return nums;  //
    for (int i = 0; i < nums.size()-1; i++)
    {
        for (int j = i+1; j < nums.size(); j++)
        {
            if (nums[i]+nums[j] == target)
            {
                nums[0]=i;
                nums[1]=j;
                nums.erase(nums.begin()+2,nums.end());
            }
            
        }
        
    }
    return nums;
}

int main()
{
    std::vector<int> vi;
    vi.push_back(2);
    vi.push_back(7);
    vi.push_back(11);
    vi.push_back(15);
    vi=twoSum(vi,9);
    for (int i:vi)
    {
        std::cout << i << " ";
    }
}