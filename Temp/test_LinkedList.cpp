/*
single LinkedList debug program
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
        if (head == nullptr) return nullptr;
        ListNode* dummy = new ListNode(-1,head);
        head = dummy;
        ListNode* fast = head;
        for (int i = 0;fast != nullptr and i < n;i++) {
            fast = fast->next;
        }
        while (fast != nullptr and fast->next != nullptr) {
            head = head->next;
            fast = fast->next;
        }
        ListNode* release = head->next;
        head->next = head->next->next;
        delete release;
        ListNode* ret = dummy->next;
        delete dummy;
        return ret;
    }
};
ListNode* buildLinkedList(std::vector<int>& nums);
void printLinkedList(const ListNode* head);

int main() {
    std::vector<int> nums;
    //LinkedList value
    for (int i = 0; i < 6; i++)
        nums.push_back(i);
    //create LinkedList
    ListNode* head = new ListNode(-1,buildLinkedList(nums));
    printLinkedList(head->next);
    //###########################################################################
    Solution Task;
    Task.removeNthFromEnd(head->next,3);
    //###########################################################################
    printLinkedList(head->next);
}

ListNode* buildLinkedList(std::vector<int>& nums) {  
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
void printLinkedList(const ListNode* head) {
    const ListNode* temp = head;
    std::cout << "LinkedList is ";
    while (temp != nullptr) {
        std::cout << temp->val << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}