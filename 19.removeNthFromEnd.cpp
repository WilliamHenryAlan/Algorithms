/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr) return head;
        //new dummy node
        ListNode* temp = new ListNode(-1);
        temp->next = head;
        head = temp;

        ListNode* fast = head,*slow = head;
        //让fast和slow指针相隔的节点的长度为n
        for (;n>0 and fast != nullptr;n--) {
            fast = fast->next;
        }
        if (n != 0) {
            head = temp->next;
            delete temp;
            return head;
        }
        else {
            while (fast->next != nullptr) { //可以让fast指针指向倒数第一个节点
                fast = fast->next;
                slow = slow->next;
            }
            //fast = fast->next;
            ListNode* temp2 = slow->next;
            slow->next = temp2->next;
            delete temp2;
            //删除dummy node
            head = temp->next;
            delete temp;
            return head;
        }
    }
};
ListNode* buildList(std::vector<int>& nums) {  
    if (nums.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(nums[0]);
    ListNode* cur = head;
    for (int i = 1; i < nums.size(); i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}
void print(const ListNode* head) {
    const ListNode* temp = head;
    std::cout << "LinkedList is ";
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
int main() {
    std::vector<int> nums;
    for (int i = 0; i < 6; i++)
    {
        nums.push_back(i);
    }
    ListNode* head = nullptr;
    head = buildList(nums);
    print(head);
    Solution A;
    head = A.removeNthFromEnd(head,2);
    print(head);
}