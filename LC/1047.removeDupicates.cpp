/*
给出由小写字母组成的字符串 S，重复项删除操作会选择两个相邻且相同的字母，并删除它们。

在 S 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。
示例：

输入："abbaca"
输出："ca"
解释：
例如，在 "abbaca" 中，我们可以删除 "bb" 由于两字母相邻且相同，这是此时唯一可以执行删除操作的重复项。之后我们得到字符串 "aaca"，其中又只有 "aa" 可以执行重复项删除操作，所以最后的字符串为 "ca"。

*/

/*
solution:

*/
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
/*
Method 1:stack
*/
class Solution {
public:
    std::string removeDuplicates(std::string s) {
        std::stack<char> st;
        for (char c:s) {
            if (!st.empty()) {
                if (st.top() != c) {
                    st.push(c);
                }else {
                    st.pop();
                }
            }else {
                st.push(c);
            }
        }
        std::string ret;
        while (!st.empty()) {
            ret.insert(0,1,st.top());
            st.pop();
        }
        return ret;
    }
};
/*
Method 2:string
*/
class Solution {
public:
    std::string removeDuplicates(std::string s) {
        std::string ret;
        for (char c:s) {
            if (ret.empty() or ret.back() != c) {
                ret.push_back(c);
            }else {
                ret.pop_back();
            }
        }
        return ret;
    }
};
int main() {
    Solution a;
    std::string str = "abbaca";
    str = a.removeDuplicates(str);
    std::cout << str << std::endl;
}
