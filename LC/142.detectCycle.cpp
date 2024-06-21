/*

*/
#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//template hash
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> visited;
        while (head != nullptr) {
            if (visited.count(head)) {
                return head;
            }
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

//2024.1.13 hash table
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr or head->next == nullptr) return nullptr;
        unordered_set<ListNode*> myset;
        ListNode* temp = head;
        while (temp != nullptr) {
            if (myset.count(temp) == 0) {
                myset.insert(temp);
            }else {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
};

//TODO
/*
 环长 = b + c
 slow_distance = a + b
 fast_distance = a + b + k * (b + c)
 
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (fast == slow) {
                while (slow != head) {
                    slow = slow->next;
                    head = head->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};