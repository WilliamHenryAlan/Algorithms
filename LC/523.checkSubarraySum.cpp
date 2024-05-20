
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        vector<int> preSum(len + 1,0);
        unordered_set<int> hash;
        for (int i = 1;i <= len;i++) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
        }
        for (int j = 2;j <= len;j++) {
            hash.insert(preSum[j - 2] % k);
            if (hash.find(preSum[j] % k) != hash.end()) return true;
        }
        return false;
    }
};