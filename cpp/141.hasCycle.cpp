#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//doubly pointer
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* slow = head,*fast = head->next;
        while (fast != nullptr && fast->next != nullptr) {
            if (slow == fast) return true;
            slow = slow->next;
            fast = fast->next->next;
        }
        return false;
    }
};
//template hashtable
class Solution {
public:
    bool hasCycle(ListNode *head) {
        std::unordered_set<ListNode*> seen;
        while (head != nullptr) {
            if (seen.count(head)) {
                return true;
            }
            seen.insert(head);
            head = head->next;
        }
        return false;
    }
};

//2024.1.12 hash table
class Solution {
public:      
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return false;
        ListNode* temp = head;
        std::unordered_set<ListNode*> mySet;
        while (temp != nullptr) {
            if (mySet.find(temp) == mySet.end()) {
                mySet.insert(temp);
                temp = temp->next;
            }else {
                return true;
            }
        }
        return false;
    }
};