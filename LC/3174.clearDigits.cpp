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

class Solution {
public:
    string clearDigits(string s) {
        string ans;
        for (char c:s) {
            if (isdigit(c)) ans.pop_back();
            else ans.push_back(c);
        }
        return ans;
    }
};