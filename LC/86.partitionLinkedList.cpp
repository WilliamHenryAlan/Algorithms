/*
solution:
Method 1 模拟：
1.维护两个LinkedList lessHead把 < x的node连接
                  moreHead把 >= x的node连接
2.head遍历结束后 把less->next = moreHead->next 
more->next = nullptr 完成less和more链表的连接 
然后释放moreHead lessHead
3.return

tips：
1.注意判断条件 只有condition为 >= 时 才连接到moreHead
2.创建dummyNode 方便链表的第一个node插入操作
3.循环结束后不要忘记把两个链表串起来 释放内存

*/
#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lessHead = new ListNode(0);
        ListNode* less = lessHead;
        ListNode* moreHead = new ListNode(0);
        ListNode* more = moreHead;
        while (head != nullptr) {
            if (head->val < x) {    // < x的插入less
                less->next = head;
                less = head;
            }else {                 // >= x的插入more
                more->next = head;
                more = head;
            }
            head = head->next;      //每次迭代head
        }   
        less->next = moreHead->next;    //完成两个链表的连接
        more->next = nullptr;
        delete moreHead;
        ListNode* ret = lessHead->next;
        delete lessHead;
        return ret;
    }
};