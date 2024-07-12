#include <iostream>
#include <math>
#include <queue>
#include <vector>
using namespace std;

/*
Method 1:simulation
可以用c++自带的priority_queue这样需要额外的空间
也可以直接堆化 再用pop_heap和push_heap维护
*/
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> q(gifts.begin(),gifts.end());
        while (k--) {
            int max = q.top();
            if (max == 1) break;
            q.pop();
            q.push(sqrt(max));
        }
        long long total = 0;
        while (!q.empty()) {
            total += q.top();
            q.pop();
        }
        return total;
    }
};
/*
2024.7.12
*/
class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq(gifts.begin(),gifts.end());
        long long ans = 0;
        while (k--) {
            int temp = sqrt(pq.top());
            pq.pop();
            pq.push(temp);
        }
        while (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
        return ans;
    }
};