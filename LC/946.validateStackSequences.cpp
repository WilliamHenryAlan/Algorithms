class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0;
        for (int& val:pushed) {
            st.push(val);
            while (!st.empty() && popped[i] == st.top()) {
                i++;
                st.pop();
            }
        }
        return st.empty();
    }
};
