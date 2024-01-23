/*
2023.12.20
*/

/*
solution:
本题暴力破解会超时
本题不能使用优先队列 因为pop操作始终pop优先级最高的元素
而应该使用单调队列 单调队列解决滑动窗口的问题尤其适用

每次滑动窗口 就会push一个elem和pop一个elem 就像一个队列一样
所以只需要维护一个单调队列 使他具有push pop和getMaxValue三个操作即可

*/
#include <iostream>
#include <vector>
#include <deque>

class Solution {
private:
    class MonotonicQueue {
        std::deque<int> deq;    //用双端队列更好操作
    public:
        void pop(int val) {
            if (!deq.empty() && deq.front() == val) {   //每次操作都要判定队列是不是为空 防止对空队列操作
                deq.pop_front();                        //只有当要pop的元素为front也就是最大元素时 才会真的弹出    
            }
        }
        void push(int val) {
            while (!deq.empty() && deq.back() < val) { //非空队列 当压入的值要大于队尾元素时 把小于的元素全部弹出
                deq.pop_back();
            }
            deq.push_back(val); //再把val压入
        }
        int top() {
            return deq.front();//由于push和pop的操作 所以每次留在front的都是最大值
        }
    };
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> ret;
        int right = k;
        int length = nums.size();
        MonotonicQueue Que;
        for (int i = 0;i < k;i++) { //先把第一个slidWindow的value全部压入队列
            Que.push(nums[i]);
        }
        ret.push_back(Que.top());   //record第一个slidWindow的MaxValue
        while (right < length) {
            Que.pop(nums[right-k]);     
            Que.push(nums[right++]);  //入队并滑动窗口
            ret.push_back(Que.top());
        }
        return ret;
    }
};
