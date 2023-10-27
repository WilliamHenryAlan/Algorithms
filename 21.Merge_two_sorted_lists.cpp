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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* ret = new ListNode();
        ListNode* prev = ret;
        while(list1 != nullptr and list2 != nullptr)
        {
            if (list1->val <= list2->val)
            {
                prev->next=list1;
                list1=list1->next;
                prev=prev->next;
            }
            else
            {
                prev->next=list2;
                list2=list2->next;
                prev=prev->next;
            }
        }
        if (list1 == nullptr)
        {
            prev->next=list2;
        }
        if (list2 == nullptr)
        {
            prev->next=list1;
        }
        ListNode*release = ret;
        ret = ret->next;
        delete release;
        return ret;
    }
};