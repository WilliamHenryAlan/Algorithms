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

/*
review 2024.6.11
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while (l1 != nullptr || l2 != nullptr) {
            int x,y,z;
            if (!l1) {
                x = 0;
            }else {
                x = l1->val;
                l1 = l1->next;
            }
            if (!l2) {
                y = 0;
            }else {
                y = l2->val;
                l2 = l2->next;
            }
            temp->next = new ListNode();
            temp = temp->next;
            z = carry + x + y;
            if (z > 9) {
                carry = 1;
                temp->val = z % 10;
            }else {
                temp->val = z;
                carry = 0;
            }
        }
        if (carry == 1) {
            temp->next = new ListNode();
            temp->next->val = 1;
        }
        return ans->next;
    }
};