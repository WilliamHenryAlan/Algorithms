
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
2024.2.27
1.处理特殊情况
2.假设nums.size() - 2是真的peak
3.算出mid 比较他和右侧的元素大小
4.如果>= 说明peak在左边 因为是闭区间 r = m - 1
5.如果是小于 说明[nums[l],nums[mid]]闭区间都是 < nums[mid + 1] => l = m + 1
这样l左侧的元素都是严格小于nums[mid + 1]的
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int l = 0,r = n - 2;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (nums[m] < nums[m + 1]) {
                l = m + 1;
            }else {
                r = m - 1;
            }
        }
        return r + 1;
    }
};
/*
review 2024.6.19
左闭右开写法 把index为m和m + 1的做对比
如果nums[m] < nums[m + 1] 说明peak在m+1及其右侧 不然在左侧
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int l = 0,r = nums.size() - 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m + 1] >= nums[m]) {
                l = m + 1;
            }else {
                r = m;
            }
        }
        return l;
    }
};