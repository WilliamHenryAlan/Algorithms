/*


1.初始化start end为0 分别记录队列头尾

2.p指针申请长度为k的空间 用数组模拟队列

3.enQueue 通过对end mod来确认实际插入位置

4.deQueue 通过移动start来删除元素（实际上没有抹去 通过replace的方式remove）

5.front&rear 如果空return -1 不然对k进行mod确认实际位置并返回 因为end指向待插入位置 所以要-1

6.isEmpty start == end时为空 不一定都是0

7.isFull end - start为左闭右开 差值为k说明已经满了

*/
class MyCircularQueue {
    int k,* p,start,end;
public:
    MyCircularQueue(int k) : p(new int[k]),k(k),start(0),end(0) {}
    bool enQueue(int value) {
        if (isFull()) return false;
        p[end % k] = value;
        end++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        start++;
        return true;
    }
    
    int Front() {
        return isEmpty()?-1:p[start % k];
    }
    
    int Rear() {
        return isEmpty()?-1:p[(end - 1) % k];
    }
    
    bool isEmpty() {
        return start == end;
    }
    
    bool isFull() {
        return end - start == k;
    }
};