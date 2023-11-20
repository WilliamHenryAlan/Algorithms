/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

 

Example 1:

Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:

Input: head = []
Output: []

Example 3:

Input: head = [1]
Output: [1]

*/
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
        if (head == nullptr or head->next == nullptr) return head;
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        head = temp;

        ListNode* prev = head,* cur = prev->next,* next = nullptr;
        while (cur != nullptr and cur->next != nullptr) {
            next = cur->next;
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
            prev = cur;
            cur = cur->next;
        }

        head = temp->next;
        delete temp;
        return head;
        
    }
};
int main() {

}