#include <iostream>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1,nullptr);
        ListNode* temp = head;  //创建dummyNode 简化边界条件计算
        int sum = 0;
        while (l1 || l2) {
            int a = l1 == nullptr?0:l1->val;    //如果l1为nullptr 表示l1遍历完了 赋值为0
            int b = l2 == nullptr?0:l2->val;    //l2同理
            sum += a + b;
            temp->next = new ListNode(sum % 10);
            sum /= 10;
            temp = temp->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (sum > 0) temp->next = new ListNode(1);
        return head->next;
    }
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* a = l1,*b = l2;
        ListNode* ret = l1;
        int carry = 0;
        while (a && b) {
            a->val += b->val + carry;
            if (a->val >= 10) {
                a->val %= 10;
                carry = 1;
            }else {
                carry = 0;
            }
            a = a->next;
            b = b->next;
        }
        return l1;
        if (!a) {

        }else {

        }
    }
};