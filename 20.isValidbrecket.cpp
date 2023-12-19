/*
2023.12.18
*/
/*
issue:
给定string 判断string中括号匹配合法性

solution：
因为涉及到抵消 想到用stack
括号非法有3种情况
1.栈空 加入为右括号
2.匹配非法
3.匹配完栈还遗留左括号

1.创建stack while循环 如果是左括号 则push
2.如果是右括号则弹出栈顶元素 匹配则pop 
                        失败则return false
3.遍历完整个string 栈非空 return false
*/

#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (auto& c:s) {
            if (c == '{' || c == '(' || c == '[') {
                st.push(c);
            }else if (st.empty()) {
                return false;
            }else if (c == '}' && st.top() != '{') {
                return false;
            }else if (c == ']' && st.top() != '[') {
                return false;
            }else if (c == ')' && st.top() != '(') {
                return false;
            }else {
                st.pop();
            }
        }
        return st.empty();
    }
};

/*
1.判断边界情况 如果string.size() == 0 return
2.循环push 三个左括号
3.遇到右括号  先判断栈是否为空 如果为空 return false
4.判断是否匹配 匹配pop 不匹配return false
5.栈为空 说明匹配正确
*/
#include <iostream>
#include <stack>
#include <string>
class Solution {
public:
     bool isValid(std::string str) {
        if (str.size()==0|str.size()==1) return false;//1。
        std::stack<char> s;
        for (int i = 0;i < str.size();i++)
        {
            if (str[i]=='(' or str[i]== '[' or str[i]=='{') //2.
            s.push(str[i]);
            else if(s.empty()) return false;    //3.
            else
            {
                if (str[i]==')' and s.top()=='(') s.pop();      //4.
                else if (str[i]==']' and s.top()=='[') s.pop();
                else if (str[i]=='}' and s.top()=='{') s.pop();
                else return false;
            }
        }
        return s.empty();
    }
};
int main()
{
    Solution a;
    std::string str ="(]";
    std::cout << a.isValid(str);
}