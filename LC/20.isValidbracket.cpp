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
#include <unordered_map>

/*
practice:
2024.1.28
tips:
1.因为涉及抵消的操作 想到符合stack的特性 可以用stack
2.括号非法的情况:
    1.遍历string 结束后栈非空
    2.遍历string 遇到右括号匹配左括号匹配失败
    3.栈空 且push右括号
3.因为这样大量使用ifelse判断是否匹配 可以用map去维护
*/
class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        std::unordered_map<char,char> bracket {
            {'}','{'},
            {']','['},
            {')','('}
        };
        for (char c:s) {
            //不论c是什么 都去find 如果找到了 说明c为右括号进行匹配
            if (bracket.find(c) != bracket.end()) {
                //如果这个时候栈空 说明栈空时进行右括号入栈 符合第3种情况 return false
                //              或者匹配失败 符合第2种情况 return false
                if (st.empty() or bracket[c] != st.top()) return false;
                //匹配成功 pop
                else st.pop();
            }else {
            //没找到 说明c为左括号 入栈
                st.push(c);
            }
        }
        return st.empty();
    }
};

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