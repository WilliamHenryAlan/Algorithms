#include <iostream>
#include <vector>
#include <deque>
using namespace std;
/*
Method 1:simulation
主要是理解题意：
1.queue的区间长度实际上是在3001个 也就是题目的[t - 3000, t]
2.在区间外的 都要pop
3.每次push 更新queue
*/
class RecentCounter {
public:
    deque<int> q;
    RecentCounter() {

    }
    
    int ping(int t) {
        q.push_back(t);
        while (q.front() < q.back() - 3000) {
            q.pop_front();
        }
        return q.size();
    }
};

