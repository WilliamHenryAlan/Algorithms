#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
review 2024.1.30
/*
tokens = ["2","1","+","3","*"]
这道题是经典的用栈解决的题目类型
后缀表达式 也就是逆波兰表达式是没有括号的
所以 遍历tokens的过程中 只会碰到operator和numbers两种情况
1.因为后缀表达式的操作符顺序其实就是运算的顺序（优先级） 所以
2.遍历tokens 如果不为operators则push
            else 弹出两个numbers 先出来的为右操作数  运算之后push
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<std::string> myStack;
        for (std::string& s:tokens) {
            if (s != "+" and s != "-" and s != "*" and s != "/") {
                myStack.push(s);
            }else {
                int right = std::stoi(myStack.top());
                myStack.pop();
                int left = stoi(myStack.top());
                myStack.pop();
                int result;
                if (s == "*") {
                    result = left * right;
                }else if(s == "/") {
                    result = left / right;
                }else if (s == "+") {
                    result = left + right;
                }else if (s == "-") {
                    result = left - right;
                }
                myStack.push(to_string(result));
            }
        }
        return stoi(myStack.top());
    }
};
/*
solution：
手动模拟：后缀表达式只会遇到两种情况 1.遇到数字 2.遇到操作符
遇到数字就压入栈中
遇到操作符 要弹出两个操作数 并执行运算 再将结果push
这种类似 弹出消除的想到栈stack
*/

class Solution {
public:

    int evalRPN(std::vector<std::string>& tokens) {
        std::stack<std::string> st;
        for (std::string& s:tokens) {
          if (s != "+" and s != "-" and s != "*" and s != "/") {
            st.push(s);
          }else {
            int right = std::stoi(st.top());
            st.pop();
            int left = std::stoi(st.top());
            st.pop();
            int result = 0;
            if (s == "*") {
              result = left * right;
            }else if(s == "/") {
              result = left / right;
            }else if (s == "+") {
              result = left + right;
            }else if (s == "-") {
              result = left - right;
            }
            st.push(std::to_string(result));
          }
        }
        return std::stoi(st.top());
    }
};