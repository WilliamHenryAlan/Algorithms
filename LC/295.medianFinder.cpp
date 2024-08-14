class MedianFinder {
    priority_queue<int> l;//左边是小根堆 m = l.size()
    priority_queue<int,vector<int>,greater<int>> r;//右边是大根堆 n = r.size()

    // 小根堆的数量奇数时比大根堆+1 也就是右侧元素数量奇数时大于左侧数量1
    // 这样 m + n 为奇数时 median = r.top()
    // 当 m + n为偶数时 median = (l.top() + r.top()) / 2
public:
    MedianFinder() {}

    void addNum(int num) {
        int m = l.size(),n = r.size();
        if (m != n) {
            r.push(num);
            l.push(r.top());
            r.pop();
        } else {
            l.push(num);
            r.push(l.top());
            l.pop();
        }
    }
    
    double findMedian() {
        int n = l.size() + r.size();
        return n % 2?r.top():(l.top() + r.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

