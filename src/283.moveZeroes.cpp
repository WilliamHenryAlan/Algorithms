#include <vector>
#include <iostream>
using namespace std;
/*
Method 1:filter
1.用filter的思想 当数组元素不为0的时候 就要这个元素 进行赋值
              为0时 不要这个元素 j一直向后遍历即可
2.双指针其实和filter是差不多的思想 j为快指针 i为慢指针
*/

//filter
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int i = 0;
        for (int j = 0;j < len;j++) {
            if (nums[j] != 0) {         //当数组元素不为0的时候 就要这个元素 进行赋值
                nums[i] = nums[j];
                i++;
            }
        }
        for (;i < len;i++) {        //补0
            nums[i] = 0;
        }
    }
};
//双指针
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int len = nums.size();
        int left = 0,right = 0;
        for (;right < len;right++) {
            if (nums[right] != 0) {
                std::swap(nums[left],nums[right]);
                left++;
            }
        }
    }
};