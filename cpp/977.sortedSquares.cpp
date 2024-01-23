// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].

// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]


// //Solution
// 1.如果都是正数 直接std::pow(nums[i],2) return 即可
// 2.因为给定的数组是有序的 而且是有负数的 所以最大的在数组的两端
// 3.双指针指向nums的两端 left=0 right=nums.size()-1
// 4.创建新的std::vector 并进行初始化 用k指向最后一个元素的下标
// 5.如果if (pow(nums[left],2) >= pow(nums[right],2)) 把left指针的数值平方再填入新数组
//         else 把left指针的数值平方再填入新数组
//         每次循环迭代k 使k-- 因为需要最后的数组为增序排列
// 6.return 新数组

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int>& nums) {
        int len=nums.size();
        std::vector<int> ret(len,0);
        int k=len-1;
        for (int left = 0,right = len-1;left<=right;)
        {
            if (pow(nums[left],2) >= pow(nums[right],2))
            {
                ret[k] = std::pow(nums[left],2);
                left++;
            }
            else
            {
                ret[k] = nums[right]*nums[right];
                right--;
            }
            k--;
        }
        return ret;
    }
};
int main()
{
    std::vector<int> vi;
    vi.push_back(-4);
    vi.push_back(-1);
    vi.push_back(0);
    vi.push_back(3);
    vi.push_back(10);
    for (int out:vi)
        std::cout << " " << out;
    std::cout << std::endl;
    std::cout << "-------------------" << std::endl;
    Solution t;
    t.sortedSquares(vi);
    for (int out:vi)
        std::cout << " " << out;   
}

//Version A violence
// class Solution {
// public:
//     std::vector<int> sortedSquares(std::vector<int>& nums) {
//         for (int& element:nums)
//             element=element*element;
//         std::sort(nums.begin(),nums.end());
//         return nums;
//     }
// };