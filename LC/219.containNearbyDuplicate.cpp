#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        for (int i = 0;i < nums.size();i++) {
            //找到了 说明存在重复元素 判断index差是否<=k
            if (hash.find(nums[i]) != hash.end()) {
                if ((i - hash[nums[i]]) <= k) {
                    return true;
                }else {
                    hash[nums[i]] = i;
                }
            }else {
                hash[nums[i]] = i;
            }
        }
        return false;
    }
};
/*
2024.7.24

1.hashtable记录数字下标 

2.遍历数组时 发现hashtable记录过 说明之前存在相同数字

则 用现在的下标 i - hashtable[nums[i]] 判断是否满足 i - cache[nums[i]] <= k 

3.无论hashtable是否存在 都要更新 处理 nums = [1,0,0,0,1,1], k = 1 这种测试案例


*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> cache;
        int n = nums.size();
        for (int i = 0;i < n;++i) {
            if (cache.contains(nums[i]) && i - cache[nums[i]] <= k) return true;
            cache[nums[i]] = i;
        }
        return false;
    }
};