/*

*/
#include <iostream>
#include <vector>
#include <algorithm>
/*
输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
*/
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        int len = nums.size();
        std::sort(nums.begin(),nums.end()); //先进行qs
        for (int i = 0;i < len;i++) {   
            if (nums[i] > 0) break; //因为已经有序 当nums[i] > 0 已经不会再出现三数之和 == 0
            if (i > 0 && nums[i] == nums[i-1])  continue;
            int left = i+1,right = len-1;   //设置left right指针指向[i+1,len-1]
            while (left <right) {       //寻找 nums[left]+nums[right] == -nums[i]
                int sum = nums[left]+nums[right];
                if (sum == -nums[i]) {
                    std::vector<int> ans = {nums[i],nums[left],nums[right]};//找到其中的一个三元组
                    ret.push_back(ans);
                    left++;
                    right--;
                    while (left < right && nums[right] == nums[right+1]) right--;   //去重
                    while (left < right && nums[left] == nums[left-1]) left++;
                }else if (sum > -nums[i]) {    //sum > -nums[i] 说明sum太大 right--
                    right--;
                }else {
                    left++;
                }
            }
        }
        return ret;
    }
};
