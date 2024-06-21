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
k = 2
head -> 1 -> 2 -> 3 -> 4 -> nullptr

1.getEnd

2.reverse

tips：
1.链表的问题画图
*/
class Solution {
public:
    //return endnode 
    //如果return == nullptr 说明最后node数量不足 不需要reverse
    ListNode* getEnd(ListNode* head,int k) {
        for (int i = 0;i < k and head != nullptr;++i) {
            head = head->next;
        }
        if (head == nullptr) return nullptr;
        return head;
    }
    void reverse(ListNode* head,ListNode* nextGrp) {
        ListNode* cur = head;
        while (cur != nextGrp) {
            ListNode* next = cur->next;
            cur->next = head;
            head = cur;
            cur = next;
        }
    }   
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* fake = new ListNode;
        fake->next = head;
        ListNode* prev = fake;
        head = fake->next;
        while (head != nullptr) {
            ListNode* end = getEnd(head,k);  
            if (end == nullptr) break;
            ListNode* nextGrop = end->next;
            reverse(head,nextGrop); 
            prev->next = end; 
            head->next = nextGrop;
            prev = head;
            head = nextGrop;
        }
        return fake->next;
    }
};

/*
2024.6.21
*/
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1,head);
        ListNode* x = head;
        head = dummy;
        int n = 0;
        while (x) {
            n++;
            x = x->next;
        }//count list node numeber
        while (n >= k) {
            n -= k; //数量不足k个 braak
            ListNode* cur = head->next,*temp = cur,*prev = nullptr,*nxt = nullptr;
            for (int i = 0;i < k;i++) {
                nxt = cur->next;
                cur->next = prev;
                prev = cur;
                cur = nxt;
            }
            head->next = prev;
            temp->next = cur;

            head = temp;//reset 哨兵节点
        }
        return dummy->next;
    }
};