/*
Method 1:hashtable
1.映射一个vector到set中
2.判断node是否存在 存在则为相交点
*/
#include <iostream>
#include <unordered_set>
struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x,ListNode* next):val(x),next(next) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> unset;
        ListNode* a = headA, *b = headB;
        while (a != nullptr) {
            unset.insert(a);
            a = a->next;
        }
        while (b != nullptr) {
            if (unset.find(b) != unset.end()) {
                return b;
            }
            b = b->next;
        }
        return nullptr;
    }
};

