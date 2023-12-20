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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* prev = new ListNode;
        prev->next = head;
        head = prev;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* traversal = prev->next;
            prev->next = traversal->next;
            traversal->next = prev->next->next;
            prev->next->next = traversal;
            prev = traversal;
        }
        prev = head;
        head = prev->next;
        delete prev;
        return head;
    }
};