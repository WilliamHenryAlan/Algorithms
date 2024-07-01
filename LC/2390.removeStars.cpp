/*
可以原地移除 时间空间复杂度达到O(n)
*/
class Solution {
public:
    string removeStars(string s) {
        int i = 0;
        for (int j = 0;j < s.size();j++) {
            if (s[j] != '*') {
                s[i++] = s[j];
            }else i--;
        }
        s.resize(i);
        return s;
    }
};


class Solution {
public:
    string removeStars(string s) {
        stack<char> st;
        for (char& c:s) {
            if (c == '*') {
                st.pop();
            }else {
                st.push(c);
            }
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};