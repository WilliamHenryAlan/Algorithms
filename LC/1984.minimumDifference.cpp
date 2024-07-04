class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int ans = INT_MAX;
        sort(nums.begin(),nums.end());
        int i = k;
        while (i <= nums.size()) {
            ans = min(ans,nums[i - 1] - nums[i - k]);
            i++;
        }
        return ans;
    }
};
