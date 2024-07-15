/*
solution:
用一个队列模仿栈
1.用一个队列模仿其实更简单 pop出的元素暂存再压回queue
2.主要实现pop和top
*/
#include <iostream>
#include <queue>
//one queue
class MyStack {
public:
    std::queue<int> q;
    MyStack() {

    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        for (int i = 0;i < q.size()-1;i++) {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        int temp = pop();
        push(temp);
        return temp;
    }
    
    bool empty() {
        return q.empty();
    }
};
//two queue
class MyStack {
public:
    std::queue<int> InQueue,OutQueue;
    MyStack() {

    }
    
    void push(int x) {
        InQueue.push(x);
    }
    
    int pop() {
        int len = InQueue.size()-1;
        for (int i = 0;i < len;i++) {
            OutQueue.push(InQueue.front());
            InQueue.pop();
        }
        int ret = InQueue.front();
        InQueue.pop();
        InQueue = OutQueue;
        while (!OutQueue.empty()) {
            OutQueue.pop();
        }
        // while (!OutQueue.empty()) {
        //     InQueue.push(OutQueue.front());
        //     OutQueue.pop();
        // }
        return ret;
    }

    
    int top() {
        int temp = pop();
        push(temp);
        return temp;
        //return InQueue.back();
    }
    
    bool empty() {
        return InQueue.empty();
    }
};

/*
2024.7.15
*/
class MyStack {
    queue<int> q;
public:
    MyStack() {}
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        int n = q.size(),temp;
        while (--n) {   //依次从front弹出加入到back 循环q.size() - 1次
            temp = q.front();
            q.pop();
            q.push(temp);
        }
        temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        int temp = pop();//复用代码pop()
        push(temp);
        return temp;
    }
    
    bool empty() {
        return q.empty();
    }
};