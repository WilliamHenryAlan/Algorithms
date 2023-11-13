/*
1.判断边界情况 如果string.size() == 0 return
2.循环push 三个左括号
3.遇到右括号  判断是否匹配 匹配pop
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
            else if(s.empty()) return false;
            else
            {
                if (str[i]==')' and s.top()=='(') s.pop();
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