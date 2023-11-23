/*
1.
*/
#include <iostream>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        if (s[0] == ']' or s[0] == ')' or s[0] == '}') return false;
        int len = s.size();
        std::stack<char> st;
        for (int i = 0;i < len;i++) {
            if (s[i] == '[' or s[i] == '(' or s[i] == '{') {
                st.push(s[i]);
            }else if (!st.empty()) {
                char temp = st.top();
                if (temp == '[' and s[i] == ']') {
                    st.pop();
                }else if (temp == '(' and s[i] == ')') {
                    st.pop();
                }else if (temp == '{' and s[i] == '}') {
                    st.pop();
                }else {
                    return false;
                }
            }else {
                return false;
            }
        }
        return st.empty();
    }
};
int main()
{
}