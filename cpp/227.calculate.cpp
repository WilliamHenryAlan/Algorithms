#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
224.基本计算器
227.基本计算器II
772.基本计算器III
拆分问题；
1.string => int
2.处理 + -
3.处理 * /
*/
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int len = s.size();
        char sign = '+';
        int num = 0;
        for (int i = 0;i < len;++i) {
            char c = s[i];
            //遇到数字 先进行累加
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            /*
            1.不能为数字 而且不能为空格
            2.当遍历到以后一个数字时 也要进行计算 如果没有i == len-1这个条件
            那么就会进入上一个if 最后一个数字的运算会被留在num中
            */
            if ((!isdigit(c) && c != ' ') || i == len-1) {
                int temp = 0;
                switch (sign) {
                    case '+':
                        stk.push(num);break;
                    case '-':
                        stk.push(-num);break;
                    case '*':
                        temp = stk.top();
                        stk.pop();
                        stk.push(temp*num);
                        break;
                    case '/':
                        temp = stk.top();
                        stk.pop();
                        stk.push(temp/num);
                        break;
                }
                sign = c;
                num = 0;
            }
        }
        //把栈中的数值进行累加
        int ans = 0;
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};