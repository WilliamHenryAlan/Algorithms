#include <vector>
#include <iostream>
#include <set>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        multiset<long> hash(nums.begin(),nums.end());
        int ans = 0;
        auto iter = hash.begin();
        while (*iter < k) {
            long x = *iter,y = *next(iter,1);
            long sum = min(x, y) * 2 + max(x, y);
            hash.insert(sum);
            iter = next(iter,2);
            ans++;
        }
        return ans;
    }
};