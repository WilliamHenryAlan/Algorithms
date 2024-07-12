
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> st;
        int n = nums.size();
        for (int i = 0;i < n;i++) {
            if (st.empty() || nums[st.back()] > nums[i]) {
                st.push_back(i);
            }
        }
        int ans = 0;
        for (int i = n - 1;i >= 0;i--) {
            while (!st.empty() && nums[i] >= nums[st.back()]) {
                ans = max(ans,i - st.back());
                st.pop_back();
            }
        }
        return ans;
    }
};
