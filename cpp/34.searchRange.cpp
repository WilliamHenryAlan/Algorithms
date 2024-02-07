#include<iostream>
#include <vector>
using namespace std;

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