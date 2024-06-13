/*
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：

实现 MyQueue 类：

    void push(int x) 将元素 x 推到队列的末尾
    int pop() 从队列的开头移除并返回元素
    int peek() 返回队列开头的元素
    boolean empty() 如果队列为空，返回 true ；否则，返回 false

说明：

    你 只能 使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
    你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。

*/
/*
1.需要两个栈才能实现 一个负责输入 一个输出 经过两次反转可以恢复先进先出
2.主要在于peek函数和pop函数的实现 peek函数只要看队头元素即可 pop需要弹出队头元素 代码可以复用
3.当push时 压入stackIn
4.peek时 如果stackOut不是空的 就先return stackOut.top()
        否则要把stackIn中全部元素先压入stackOut栈 再实行stackOut.top()
5.pop函数只需要调用peek函数 创建临时变量接受 然后stackOut.pop() 返回临时变量
*/
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
int main() {

}
/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */