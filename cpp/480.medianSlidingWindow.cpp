
#include <iostream>
#include <vector>
#include <set>
using namespace std;
/*
nums有序的情况下
如果是奇数：k % 2 = 1
(nums[mid] + nums[mid]) / 2
如果是偶数：k % 2 = 0
(nums[mid] + nums[mid - 1]) / 2
*/

vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> ret;
    multiset<int> window(nums.begin(), nums.begin() + k); // 初始化set,将前k个数存入set
    auto mid = std::next(window.begin(), k / 2); // 基数：获取中数的位置，偶数：获取中数计数参数的后一个数的位置
    for (int idx = k; ; idx++) {
        // 1、计数每组窗口中数组的中数，并存入ret中
        auto midValue = ((double)(*mid) + (double)*next(mid, k % 2 - 1)) / 2;
        ret.push_back(midValue);
        
        // 遍历完了，退出
        if (idx == nums.size()) {
            break;
        }

        // 窗口后移
        window.insert(nums[idx]);
        if (nums[idx] < *mid)
            mid--;                  // same as mid = prev(mid)

        // Remove outgoing element
        if (nums[idx - k] <= *mid)
            mid++;                  // same as mid = next(mid)

        // 删除一个元素
        window.erase(window.lower_bound(nums[idx-k]));
    }

    return ret;
}