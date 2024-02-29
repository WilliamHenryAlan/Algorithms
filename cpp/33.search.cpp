#include <iostream>
#include <vector>
using namespace std;
/*
第一次二分
1.假设最小值在最后
2.每次比较最后一个元素和middle元素的大小
3.如果小 说明新的更小的元素找到了
4.如果大 说明假定的是真的 移动left

第二次二分
1.二分查找判断target索引
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //用[)区间
        //假设最后一个是最小值先寻找最小值 就可以确定旋转点
        int l = 0,r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;//防止溢出处理
            if (nums[m] <= nums[r]) {
                r = m;
            }else {
                l = m + 1;
            }
        }
        //循环结束 l = r 都会指向最小值的索引
        int left, right;
        if (target >= nums[0] && r != 0 && target <= nums[r - 1]) {
            left = 0;
            right = r - 1; 
        }else {
            left = r;
            right = nums.size() - 1;
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }else if (nums[mid] < target) {
                left = mid + 1;
            }else {
                right = mid - 1;
            }
        }
        return -1;
    }
};