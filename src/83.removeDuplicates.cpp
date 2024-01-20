/**思路没写完整
 * issue:删除linkedlist中重复元素
 * 
 * solution：
 * 采用双指针 和数组删除重复元素一样的思路
 * 
*/
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x,ListNode* next):val(x),next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        ListNode* cur = head;   //指向第一个node
        ListNode* next = cur->next; //始终指向下一个node
        while (next != nullptr) {
            if (next->val == cur->val) {    //如何值相等 next向后遍历
                next = next->next;
            }else {                         //如果不想等 把cur的next指向next的node
                cur->next = next;   
                cur = next;
                next = next->next;
            }
        }
        cur->next = next;       //如果是2 2 2 2 2 2 2 2 2
        return head;
    }
};