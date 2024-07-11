
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<int> st;
        for (;head != nullptr;head = head->next) {
            while (!st.empty() && ans[st.top()] < head->val) {
                ans[st.top()] = head->val;
                st.pop();
            }
            st.push(ans.size());
            ans.push_back(head->val);//其实就是动态的把list转化为array
        }
        while (!st.empty()) {
            ans[st.top()] = 0;
            st.pop();
        }
        return ans;
    }
};

