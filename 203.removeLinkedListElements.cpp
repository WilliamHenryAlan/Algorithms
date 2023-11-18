/*
Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

 

Example 1:

Input: head = [1,2,6,3,4,5,6], val = 6
Output: [1,2,3,4,5]

Example 2:

Input: head = [], val = 1
Output: []

Example 3:

Input: head = [7,7,7,7], val = 7
Output: []
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 **/
struct ListNode {
    int val;
    ListNode* next;
};
#include <iostream>
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr) return head;
        ListNode* prev=nullptr,*current = head;
        while (current != nullptr and current->val == val)  //current != nullptr and current->val == val 两个条件不能调换顺序 
        {                                                   //不然compiler会报错 因为current如果是空指针 current->val是未定义操作
            head=head->next;
            delete current;
            current=head;
        }
        while (current != nullptr)
        {
            if (current->val == val)
            {
                prev->next=current->next;
                delete current;
                current=prev->next;
            }
            else
            {
                prev=current;
                current=current->next;
            }
               
        }
        return head;
    }
};
//Version B Dummy head node
//创建一个虚拟头节点 让prev指针指向虚拟头节点 结束后delete dummy head node 并返回

// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) {
//         ListNode* L=new ListNode;
//         L->next=head;
//         ListNode* prev=L;
//         for (;head != nullptr;)
//         {
//             if (head->val == val)
//             {
//                 prev->next=head->next;
//                 delete head;
//                 head=prev->next;
//                 continue;
//             }
//             prev=head;
//             head=head->next;
//         }
//         ListNode* temp=L->next;
//         delete L;
//         return temp;
        
//     }
// };