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
/*
2024.7.8
*/
/*
用vector模拟单调栈
压入的是index
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n,0),st;
        for (int i = 0;i < n;i++) {
            int x = temperatures[i];
            while (!st.empty() && x > temperatures[st.back()]) { //找到了之后更高的温度
                ans[st.back()] = i - st.back();
                st.pop_back();
            }
            st.push_back(i);
        }
        return ans;
    }
};
//用栈实现单调栈
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans(temperatures.size(),0);
        for (int i = 0;i < temperatures.size();i++) {
            int x = temperatures[i];
            while (!st.empty() && x > temperatures[st.top()]) { //找到了之后更高的温度
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};

