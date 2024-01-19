#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/*
Method 1：Monotone Stack
1.创建一个vector 这样没有写入的将默认为0 符合题目要求
2.for遍历 当栈非空 并且 当前温度低于栈顶(压入为index)时 循环

tips:
1.循环条件要注意 栈非空不能执行stack.top()
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> st;
        int len = temperatures.size();
        std::vector<int> res(len,0);
        for (int i = 0;i < len;i++) {
            int topIndex = st.top();    //压栈的是index
            while (st.size() > 0 and temperatures[i] > temperatures[topIndex]) {    //当栈非空并且当前温度高于temperatures[st.top()])
                res[topIndex] = i-topIndex;
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};