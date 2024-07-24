/*
和198题的区别在于 这个数组是环状的 

也就是选了最后一个不能选第一个 选了第一个不能选最后一个两种情况

n = nums.size();

那么我们只需要把[0,nums.size() - 2](选头不选尾) 和 [1,nums.size() - 1](选尾不选头)

*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        return max(dp(nums,0,nums.size() - 1),dp(nums,1,nums.size()));
    }
    int dp(const vector<int>& nums, int start,int end) {
        unordered_map<int,int> cache;
        function<int(int)> dfs = [&](int i) {
            if (i < start) return 0;
            if (cache.contains(i)) return cache[i];
            int ans = max(dfs(i - 1),dfs(i - 2) + nums[i]);
            cache[i] = ans;
            return ans;
        };
        return dfs(end - 1);
    }
};
