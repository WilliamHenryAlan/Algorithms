#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
1.假设最小值在最后 
2.每次比较最后一个元素和middle元素的大小
3.如果小 说明新的更小的元素找到了
4.如果大 说明假定的是真的 移动left
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        //左闭右闭区间写法
        int l = 0,r = nums.size() - 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] <= nums[r + 1]) {
                r = m - 1;
            }else {
                l = m + 1;
            }
        }
        return nums[r + 1];
    }
};
class Solution {
public:
    int findMin(vector<int>& nums) {
        //左闭右开写法 此时就假设nums[r]为最小值了
        int l = 0,r = nums.size() - 1;
        while (l < r) { //同时 左闭右开写法 l = r 时是无意义的
            int m = l + (r - l) / 2;
            if (nums[m] <= nums[r]) {
                r = m;
            }else {
                l = m + 1;
            }
        }
        return nums[r];
    }
};