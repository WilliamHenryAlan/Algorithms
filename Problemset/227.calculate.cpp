#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
224.基本计算器
227.基本计算器II
772.基本计算器III
*/

class Solution {
public:
    void removeSpace(string& str) {
        str.erase(remove(str.begin(), str.end(), ' '), str.end());
    }

    void calcu() {
        if (nums.size() < 2 || ops.empty()) return;
        int b = nums.top(); nums.pop();
        int a = nums.top(); nums.pop();
        char op = ops.top(); ops.pop();
        int result = 0;
        if (op == '+') {
            result = a + b;
        } else if (op == '-') {
            result = a - b;
        }
        nums.push(result);
    }

    bool checkDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    int calculate(string s) {
        // 避免开头出现'-'
        nums.push(0);
        // 去除所有' '
        removeSpace(s);
        int n = s.size();
        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == '(') {
                ops.push(ch);
            } else if (ch == ')') {
                // 直到遇到'('
                while (!ops.empty()) {
                    char op = ops.top();
                    if (op != '(') {
                        calcu();
                    } else {
                        // 遇到‘（’ pop并break
                        ops.pop();
                        break;
                    }
                }
            } else {
                if (checkDigit(ch)) {
                    int sum = 0;
                    int j = i;
                    while (j < n && checkDigit(s[j])) {
                        sum = sum * 10 + (s[j++] - '0');
                    }
                    nums.push(sum);
                    i = j - 1;
                } else {
                    // 处理操作符
                    if (i > 0 && (s[i - 1] == '(' || s[i - 1] == '+' || s[i - 1] == '-')) {
                        nums.push(0);
                    }
                    // 确保ops栈中优先级低于当前运算符的运算都执行完
                    while (!ops.empty() && ops.top() != '(') {
                        calcu();
                    }
                    ops.push(ch);
                }
            }
        }
        // 最后计算剩余的运算
        while (!ops.empty()) {
            calcu();
        }
        return nums.top();
    }

private:
    stack<int> nums;  // 存储number
    stack<char> ops;  // 存储operator
};



class Solution {
public:
    int calculate(string s) {
        stack<int> ops;
        ops.push(1);
        int sign = 1;

        int ret = 0;
        int n = s.length();
        int i = 0;
        while (i < n) {
            if (s[i] == ' ') {
                i++;
            } else if (s[i] == '+') {
                sign = ops.top();
                i++;
            } else if (s[i] == '-') {
                sign = -ops.top();
                i++;
            } else if (s[i] == '(') {
                ops.push(sign);
                i++;
            } else if (s[i] == ')') {
                ops.pop();
                i++;
            } else {
                long num = 0;
                while (i < n && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    i++;
                }
                ret += sign * num;
            }
        }
        return ret;
    }
};