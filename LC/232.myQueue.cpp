#include <iostream>
#include <stack>
class MyQueue {
private:
    std::stack<int> In;
    std::stack<int> Out;
public:
    MyQueue() {
    }
    
    void push(int x) {
        In.push(x);
    }
    
    int pop() {
        int ret = peek();
        Out.pop();
        return ret;
    }
    
    int peek() {
        if (Out.empty())
        {
            while (!In.empty()) {
                Out.push(In.top());
                In.pop();
            }
            return Out.top();
        }
        return Out.top();
    }
    
    bool empty() {
        return In.empty() and Out.empty();
    }
};

//2024.7.15
class MyQueue {
    stack<int> in,out;
public:
    MyQueue() {}
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int temp = peek();
        out.pop();
        return temp;
    }
    
    int peek() {
        if (out.empty()) {//如果out为空 说明数据都在in中 需要把in=>out
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            return out.top();
        }
        return out.top();
    }
    
    bool empty() {
        return in.empty() && out.empty();//in和out共同存储数据
    }
};
