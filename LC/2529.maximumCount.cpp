class Solution {
public:
    int maximumCount(vector<int>& nums) {
        function<int(int)> f = [&](int target) {
            int l = 0, r = nums.size() - 1;
            while (l <= r) {
                int m = l + (r - l) / 2; // 防止溢出
                if (nums[m] >= target) r = m - 1;
                else l = m + 1;
            }
            return l;
        };
        int l = f(0);//l左侧也就是l - 1以及之前都是 < 0
        int r = f(1);//r及其右侧都是 >=1 也就是 > 0
        if (l - 1 == -1 && r == nums.size()) return 0; //针对都是0的用例
        return nums.size() - r > l?nums.size() - r:l;//可以用max替代
    }
};