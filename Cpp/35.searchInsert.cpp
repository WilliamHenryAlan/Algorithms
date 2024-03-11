/*
2023.12.21

issue:返回target值的index
solution：
使用binarySearch
但是这道题找不到要return插入的index 所以
返回值究竟是什么？
如果数组中没有target，那么跳出循环前的一步一定是mid=left=right

array: 3 5 7    target = 4  left = right = mid = 1      
index: 0 1 2    nums[mid] > target => right = mid-1 left = 1

array: 3 5 7    target = 6  left = right = mid = 1
index: 0 1 2    nums[mid] < target => left = mid+1 = 2

可以看出left始终是要插入的index

*/
#include <iostream>
#include <vector>
class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int mid;
        while (left <= right) {
            mid = (left+right)/2;
            if (nums[mid] == target) {
                return mid;
            }else if (nums[mid] > target) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return left;
    }
};