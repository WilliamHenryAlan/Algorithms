class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l = 0,r = 0;
        for (int val:nums) {
            if (val < 10) l += val;
            else r += val;
        }
        return l != r;
    }
};
