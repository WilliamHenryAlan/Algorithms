class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> st,ans(n,-1);
        for (int i = 0;i < 2 * n;i++) { //遍历两次
            int x = nums[i % n];    //取模控制index在[0-n)
            while (!st.empty() && x > nums[st.back()]) {
                ans[st.back()] = x;
                st.pop_back();
            }
            if (i < n) {
                st.push_back(i);
            }
        }
        return ans;
    }
};