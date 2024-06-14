#include<iostream>
#include <vector>
using namespace std;

/*
review 2024.2.27
*/
class Solution {
    // lower_bound 返回最小的满足 nums[i] >= target 的 i
    // 如果数组为空，或者所有数都 < target，则返回 nums.size()
    // 要求 nums 是非递减的，即 nums[i] <= nums[i + 1]

    // 闭区间写法
    int lower_bound(vector<int> &nums, int target) {
        int left = 0, right = (int) nums.size() - 1; // 闭区间 [left, right]
        while (left <= right) { // 区间不为空
            // 循环不变量：
            // nums[left-1] < target
            // nums[right+1] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1; // 范围缩小到 [mid+1, right]
            } else {
                right = mid - 1; // 范围缩小到 [left, mid-1]
            }
        }
        return left;
    }

    // 左闭右开区间写法
    int lower_bound2(vector<int> &nums, int target) {
        int left = 0, right = nums.size(); // 左闭右开区间 [left, right)
        while (left < right) { // 区间不为空
            // 循环不变量：
            // nums[left-1] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1; // 范围缩小到 [mid+1, right)
            } else {
                right = mid; // 范围缩小到 [left, mid)
            }
        }
        return left; // 返回 left 还是 right 都行，因为循环结束后 left == right
    }

    // 开区间写法
    int lower_bound3(vector<int> &nums, int target) {
        int left = -1, right = nums.size(); // 开区间 (left, right)
        while (left + 1 < right) { // 区间不为空
            // 循环不变量：
            // nums[left] < target
            // nums[right] >= target
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid; // 范围缩小到 (mid, right)
            } else {
                right = mid; // 范围缩小到 (left, mid)
            }
            // 也可以这样写
            // (nums[mid] < target ? left : right) = mid;
        }
        return right;
    }

public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int start = lower_bound(nums, target); // 使用其中一种写法即可
        if (start == nums.size() || nums[start] != target) {
            return {-1, -1};
        }
        // 如果 start 存在，那么 end 必定存在
        int end = lower_bound(nums, target + 1) - 1;
        return {start, end};
    }
};


/*
review 2024.6.14
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lower_bound1(nums,target);
        if (start == nums.size() || nums[start] != target) return {-1,-1};
        int end = lower_bound2(nums,(target + 1)) - 1;
        return {start,end};
    }
    int lower_bound1(vector<int>& nums, int target) {
        int l = 0,r = nums.size() - 1;
        int m;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            }else {
                r = m - 1;
            }
        }
        return l;
    }
    int lower_bound2(vector<int>& nums, int target) {
        int l = 0,r = nums.size();
        int m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (nums[m] < target) {
                l = m + 1;
            }else {
                r = m;
            }
        }
        return l;
    }
};


/*
review 2024.2.7
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = lower_bound(nums,target);
        if (l == nums.size() || nums[l] != target) return {-1,-1};
        int r = upper_bound(nums,target);
        return {l,r};
    }
    int lower_bound(vector<int>& nums,int target) {
        int l = 0,r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        return l;
    }
    int upper_bound(vector<int>& nums,int target) {
        int l = 0,r = nums.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] > target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l-1;
    }
};


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1,-1};
        int leftIndex = binarySearch(nums,target);
        if (leftIndex == nums.size() || nums[leftIndex] != target) return result; //如果所有数都比target小 left会到right的右边 也就等于数组长度
        int rightIndex = binarySearch(nums,target+1);
        return {leftIndex,rightIndex-1};
    }
    int binarySearch(vector<int>& nums,int target) {
        int l = 0;
        int r = nums.size()-1;  //采取[]区间
        while (l <= r) {
            int mid = (r + l) / 2;
            if (nums[mid] < target) { //确定了一半元素 此时 [l,mid] < target 所以[mid+1,r]是不确定的 所以l = mid+1
                l = mid + 1;    //此时为[mid+1,r]区间 循环不变量l - 1 < target
            }else {
                r = mid - 1;    //循环不变量 r + 1 >= target
            }
        }
        return l;   //l = r+1
    }
};