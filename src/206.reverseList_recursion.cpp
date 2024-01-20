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

/*

*/
#include <iostream> 
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* reverse(ListNode* cur,ListNode* prev) {
        if (cur == nullptr) return prev;
        ListNode* temp = cur->next;
        cur->next = prev;
        return reverse(temp,cur);
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head,nullptr);
    }
};

int main()
{
    
}