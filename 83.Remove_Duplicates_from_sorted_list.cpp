/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* fast=head,*low=head;
        while (fast != nullptr)
        {
            if (fast->val == low->val)
            {
                fast=fast->next;
            }
            else
            {
                low->next=fast;
                low=fast;
            }
        }
        low->next=fast;
        return head;
    }
};