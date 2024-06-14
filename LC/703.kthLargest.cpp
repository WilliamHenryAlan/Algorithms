#include <queue>
#include <iostream>
using namespace std;

class KthLargest {
private:
    priority_queue<int,great<int>> pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int& elem:nums) {
            add(elem);
        }
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) {
            pq.pop();
        }
        return pq.top();
    }
};

int main () {

}