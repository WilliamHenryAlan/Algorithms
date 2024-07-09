/*
1.用vector模拟维护一个递增stack
2.如果比最后一个元素（栈顶元素）大 直接push
3.否则 循环弹出满足条件（小于等于最后一个元素（栈顶元素））的元素 并写入答案
*/
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> st;
        int n = prices.size();
        for (int i = 0;i < n;i++) {
            while (!st.empty() && prices[st.back()] >= prices[i]) {
                prices[st.back()] -= prices[i];
                st.pop_back();
            }
            st.push_back(i);
        }
        return prices;
    }
};
