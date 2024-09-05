class Solution {
public:
    string clearDigits(string s) {
        stack<int> st;
        for (char c:s) {
            if (isdigit(c)) st.pop();
            else st.push(c);
        }
        string ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
