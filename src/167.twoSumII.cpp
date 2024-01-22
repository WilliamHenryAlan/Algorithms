#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Method 1: hashtable
1.omit
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int> hashmap;
        int len = numbers.size();
        for (int i = 0;i < len;i++) {
            hashmap[numbers[i]] = i;
        }
        for (int i = 0;i < len;i++) {
            int temp = target-numbers[i];
            if (hashmap.find(temp) != hashmap.end()) {
                return {i+1,hashmap[temp]+1};
            }
        }
        return {};
    }
};

/*
Method 2:相向双指针
1.left和right指针指向左右
2.每次循环遍历计算*left+*right 并和 target进行比较
                                    如果 > target => right--
                                        < target => left--
tips:
1.题目要求index从1开始
*/
//因为数组是有序的 所以大小已经知道了
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size();
        for (int left = 0,right = len-1; left < right;) {
            int sum = numbers[left]+numbers[right];
            if (sum == target) {
                return {left+1,right+1};
            }else if (sum > target) {   //比target大 所以value大的下标需要移动
                right--;
            }else {                     //比target小 所以value小的下标需要移动
                left++;
            }
        }
        return {};
    }
};
//优化后代码在上^
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int len = numbers.size();
//         for (int left = 0,right = len-1; left < right;) {
//             int sum = numbers[left]+numbers[right];
//             if (sum == target) {
//                 return {left+1,right+1};
//             }else if (sum > target) {   //比target大 所以value大的下标需要移动
//                 numbers[left] > numbers[right] ? left++:right--;
//             }else {                     //比target小 所以value小的下标需要移动
//                 numbers[left] > numbers[right] ? right--:left++;
//             }
//         }
//         return {};
//     }
// };

//review    2024.1.22
/*
double pointer
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::sort(nums.begin(),nums.end());
        int len = nums.size();
        int l = 0,r = len-1;
        while (l < r) {
            int sum = nums[l]+nums[r];
            if (sum == target) {
                return {l+1,r+1};
            } else if (sum > target)
                 r--;
            else {
                l++;
            }
        }
        return {};
    }
};