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