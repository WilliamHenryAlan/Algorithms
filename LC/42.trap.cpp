#include <iostream>
#include <stack>
#include <vector>
using namespace std;
/*
Method 1:前后缀
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        vector<int> pre_max(len,0);
        pre_max[0] = height[0];
        for (int i = 1;i < len;i++) {
            pre_max[i] = max(height[i],pre_max[i-1]);
        }
        vector<int> suf_max(len,0);
        suf_max[len-1] = height[len-1];
        for (int i = len-2;i >= 0;i--) {
            suf_max[i] = max(height[i],suf_max[i+1]);
        }
        int ans = 0;
        for (int i = 0;i < len;i++) {
            ans += (min(pre_max[i],suf_max[i]) - height[i]) * 1;
        }
        return ans;
    }
};
/*
Method 2:双指针
其实就是动态维护了前后缀和 使空间复杂度为O(1)
要明白雨水的面积是怎么算的
*/

class Solution {
public:
    int trap(vector<int>& height) {
    }
};

/*
Method 3:monotone stack
*/
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