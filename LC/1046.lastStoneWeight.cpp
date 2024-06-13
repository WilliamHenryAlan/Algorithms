#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> q;
        for (int& val:stones) q.push(val); //把所有数据push进heap 会自动排序
        while (q.size() > 1) {
            int x = q.top();    //取出最大的两个x和y
            q.pop();
            int y = q.top();
            q.pop();
            if (x != y) q.push(x - y);  //如果不想等 相减之后push
        }
        return q.empty() ? 0:q.top();
    }
};