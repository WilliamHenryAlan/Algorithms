#include<iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
Method: PrefixSum + Hash

*/
class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        long long ans = LLONG_MIN, sum = 0;
        unordered_map<int, long long> min_s;
        for (int x: nums) {
            auto it = min_s.find(x + k);
            if (it != min_s.end()) {
                ans = max(ans, sum + x - it->second);
            }

            it = min_s.find(x - k);
            if (it != min_s.end()) {
                ans = max(ans, sum + x - it->second);
            }

            it = min_s.find(x);
            if (it == min_s.end() || sum < it->second) {
                min_s[x] = sum;
            }
            sum += x;
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
    }
};