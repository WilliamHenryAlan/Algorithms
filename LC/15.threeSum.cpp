/*

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
要求三个数相加 == 0
1.先排序
2.难点在于去重 
            1.首先i需要去重 if (i > 0 && nums[i] == nums[i-1])  continue;
            2.left++;
              right--;
            while (left < right && nums[right] == nums[right+1]) right--;
            while (left < right && nums[left] == nums[left-1]) left++;
3.双指针寻找后两个元素之和等于第一个元素的相反数
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
/*
review 2024.2.6
tips：1.去重方法要注意细节
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for (int i = 0;i < nums.size()-2;i++) {
            if (nums[i] > 0) break;
            int l = i+1;
            int r = nums.size()-1;
            while (l < r) {
                int sum = nums[l] + nums[r];
                if (sum + nums[i] == 0) {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l-1] == nums[l]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r+1]) {
                        r--;
                    }
                }else if (sum > -nums[i]) {
                    r--;
                }else {
                    l++;
                }
            }
        }
        return ans;
    }
};