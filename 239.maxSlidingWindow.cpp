/*
2023.12.20
*/

/*
solution:
本题暴力破解会超时
本题不能使用优先队列 因为pop操作始终pop优先级最高的元素
而应该使用单调队列 单调队列解决滑动窗口的问题尤其适用

1.

*/
#include <iostream>
#include <vector>
#include <deque>

using namespace std;
class Solution {
private:
    class MonotonicQueue {
        std::deque<int> deq;
    public:
        void pop(int val) {
            if (!deq.empty() && deq.front() == val) {
                deq.pop_front();
            }
        }
        void push(int val) {
            while (!deq.empty() && deq.back() <= val) {
                deq.pop_back();
            }
            deq.push_back(val);
        }
        int top() {
            return deq.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> ret;
        int left = 0;
        int right = k;
        int length = nums.size();
        MonotonicQueue Que;
        for (int i = 0;i < k;i++) {
            Que.push(nums[i]);
        }
        ret.push_back(Que.top());
        for (;right < length;right++,left++) {
            Que.push(nums[right]);
            Que.pop(nums[left]);
            ret.push_back(Que.top());
        }
        return ret;
    }
};