#include <iostream>
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
/*
template
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(-1);

        ListNode* prev = preHead;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // 合并后 l1 和 l2 最多只有一个还未被合并完，我们直接将链表末尾指向未合并完的链表即可
        prev->next = l1 == nullptr ? l2 : l1;

        return preHead->next;
    }
};


/*
2024.1.27

*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(-1);
        ListNode *k = ret;
        while (l1 != nullptr and l2 != nullptr) {
            if (l1->val <= l2->val) {
                k->next = l1;
                l1 = l1->next;
            }else {
                k->next = l2;
                l2 = l2->next;
            }
            k = k->next;
        }
        k->next = (l1 == nullptr ? l2:l1);
        return ret->next;
    }
};


/*
2023.12.18
issue:
两个升序linkedlist进行merge
solution：
要满足空间复杂度O(1)
创建两个指针分别比较两个LinkedList 按升序排列对比合并

1.创建指针a指向list1，b指向list2
2.创建dummy结点和返回的指针ret
3.循环对比 如果a->val>b->val 就把ret指针的linkedlist的tailNode指针指向b 并且b向后遍历
4.条件为a != nullptr && b!= nullptr 当两个list其中一个遍历结束后 把没比对完的list直接加入retList
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* a = list1,*b = list2;
        ListNode* head = new ListNode;
        ListNode* ret = head;
        while (a != nullptr && b != nullptr) {
            if (a->val > b->val) {
                ret->next = b;
                b = b->next;
            }else {
                ret->next = a;
                a = a->next;
            }
            ret = ret->next;
        }
        if (a == nullptr) {
            ret->next = b;
        }
        if (b == nullptr) {
            ret->next = a;
        }

        ret = head->next;
        delete head;
        return ret;
    }
};