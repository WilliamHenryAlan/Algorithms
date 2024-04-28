#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
/*
Method 1:双指针滑动窗口+set
滑动窗口遍历数组寻找符合要求的subarray
1.用multiset或者map维护滑动窗口
2.因为map有序 底层用RBT实现 所以每次判断最大值减去最小值是否满足 < limit

tips:
1.不能用set 虽然set有序 可以找到最大最小值 但是因为set自带去重 
所以滑动窗口左指针左滑时 erase操作会直接删除元素 当元素出现多次 比如{2,2,2,4} limit = 0
删除2之后left迭代将找不到之后的两个2 此时set中最大最小都是4
*/

//mulitiset implementionation
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0,r = 0;
        int ret = 0;
        int len = nums.size();
        multiset<int> record;
        while (r < len) {
            record.insert(nums[r]);
            //底层实现为RBT 有序排列的第一个是最小值 最后一个是最大值
            while (*record.rbegin() - *record.begin() > limit) {    
                //不能直接erase(nums[l++]) 这样会把所有等于nums[l++]的元素全部删除
                record.erase(record.find(nums[l++]));  //如果存在重复 只删除一个
            }
            ret = max(ret,r - l + 1);
            ++r;
        }
        return ret;
    }
};

//map implementionation
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int l = 0, r = 0;
        int ret = 0;
        int len = nums.size();
        map<int, int> record;
        while (r < len) {
            record[nums[r]]++;
            while (record.rbegin()->first - record.begin()->first > limit) {
                record[nums[l]]--;
                if (record[nums[l]] == 0) { //当nums[l]对应的value = 0时 应该erase
                    record.erase(nums[l]);
                }
                l++;
            }
            ret = max(ret, r - l + 1);
            ++r;
        }
        return ret;
    }
};
