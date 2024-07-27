#include "stack.hpp"
#include <iostream>

int main() {
    try {
        // 创建一个堆栈并初始化
        stack s1(5, 10);
        s1.print();

        // 测试push操作
        int val = 20;
        s1.push(val);
        s1.print();

        // 测试pop操作
        s1.pop();
        s1.print();

        // 创建一个空的堆栈并尝试pop
        stack s2;
        s2.pop();
    }
    catch (const stack::overflow &e) {
        std::cerr << "Error: stack overflow!" << std::endl;
    }
    catch (const stack::underflow &e) {
        std::cerr << "Error: stack underflow!" << std::endl;
    }
    catch (const stack::isempty &e) {
        std::cerr << "Error: stack is empty!" << std::endl;
    }

    return 0;
}
