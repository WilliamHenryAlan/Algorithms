
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        auto f = [&](int l,int r) {
            return to_string(nums[l]) + (l == r ? "" : "->" + to_string(nums[r]));
        };
        vector<string> ans;
        int i = 0,j = 0;
        int len = nums.size();
        for (;j < len;j++) {
            while (j < len - 1 && nums[j + 1] == nums[j] + 1) j++;
            ans.push_back(f(i,j));
            i = j + 1;
        }
        return ans;
    }
};