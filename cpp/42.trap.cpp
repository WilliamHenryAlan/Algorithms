#include <iostream>
#include <stack>

class Solution {    
public:
    int trap(std::vector<int> height) {
        int size = height.size();
        if (size <= 2) return 0;   
        int volume = 0;
        std::stack<int> MonotoneStack;  //创建单调栈
        MonotoneStack.push(0);
        for (int i = 1;i < size;i++) {
            if (height[i] < height[MonotoneStack.top()]) //右边柱子的高度大于栈顶元素 压栈
                MonotoneStack.push(i);
            else if (height[i] == height[MonotoneStack.top()]) { //右边柱子和左边柱子一样高 先弹出 再入栈
                MonotoneStack.pop();
                MonotoneStack.push(i);
            }else {
                while (!MonotoneStack.empty() and height[i] > height[MonotoneStack.top()]) {
                    int middleIndex = MonotoneStack.top();
                    MonotoneStack.pop();
                    if (!MonotoneStack.empty()) {
                        int h = std::min(height[MonotoneStack.top()],height[i]) - height[middleIndex];
                        int w = i  - MonotoneStack.top() - 1;
                        volume += h*w;
                    }
                }
                MonotoneStack.push(i);
            }
        }
        return volume;
    }
};

class Solution {    
public:
    int trap(std::vector<int> height) {
        int size = height.size();
        if (size <= 2) return 0;   
        int volume = 0;
        std::stack<int> MonotoneStack;  //创建单调栈
        MonotoneStack.push(0);
        for (int i = 1;i < size;i++) {
            while (!MonotoneStack.empty() and height[i] > height[MonotoneStack.top()]) {
                int middleIndex = MonotoneStack.top();
                MonotoneStack.pop();
                if (!MonotoneStack.empty()) {
                    int h = std::min(height[MonotoneStack.top()],height[i]) - height[middleIndex];
                    int w = i  - MonotoneStack.top() - 1;
                    volume += h*w;
                }
            }
            MonotoneStack.push(i);
        }
        return volume;
    }
};