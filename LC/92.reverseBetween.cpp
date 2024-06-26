#include <iostream> 
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/*
与反转链表类似 这题要求部分反转 类比反转整个链表
left的前一个node就是headNode
right的下一个node就是nullptr
但是要考虑特殊情况left = 1时 没有前一个node 所以使用dummyNode解决这个问题
*/
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1,head);
        ListNode* temp = dummy;
        for (int i = 0;i < left - 1;i++) {
            temp = temp->next;
        }
        ListNode* prev = nullptr,* cur = temp->next;
        int cnt = right - left + 1;
        while (cnt--) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        temp->next->next = cur;
        temp->next = prev;
        return dummy->next;
    }
};

/*
review 2024.6.20
*/

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int cnt = right - left + 1;
        ListNode* dummy = new ListNode(-1,head);
        head = dummy;
        while (--left) {
            head = head->next;
        }
        ListNode* cur = head->next,*temp = cur,*prev = nullptr,*nxt = nullptr;
        while (cnt--) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        head->next = prev;
        temp->next = cur;
        return dummy->next;
    }
};