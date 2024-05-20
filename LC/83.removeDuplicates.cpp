/**思路没写完整
 * issue:删除linkedlist中重复元素
 * 
 * solution：
 * 采用双指针 和数组删除重复元素一样的思路
 * 
*/
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int x):val(x),next(nullptr) {}
    ListNode(int x,ListNode* next):val(x),next(next) {}
};
/*
review 2024.2.16
tips：cur为当前node cur->next为下一个node
        不用遍历整个list 使用cur->next != nullptr可以使list遍历到最后一个node
        如果值重复 也就是 cur->next->val == cur->val 只需要释放cur->next 并重新link
        如果不重复 cur进行下一次遍历
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* cur = head;
        while (cur->next) {         //遍历到最后一个node
            if (cur->next->val == cur->val) {
                /*      手动释放内存
                ListNode* temp = cur->next;
                cur->next = temp->next;
                delete temp;
                */
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
/*
review 2024.2.16
tips:因为已经排序 所以可以用数组去重的思想
    缺点是 进行了assignment 当val过大不适用
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        ListNode* former = head, *latter = head;
        while (former != nullptr) {
            if (former->val != latter->val) {
                latter = latter->next;
                latter->val = former->val;
            }
            former = former->next;
        }
        latter->next = nullptr;
        return head;
    }
};

/*
可以只遍历到最后一个node 而不遍历整个list
*/
// class Solution {
// public:
//     ListNode* deleteDuplicates(ListNode* head) {
//         if (head == nullptr) {
//             return head;
//         }
//         ListNode* cur = head;   //指向第一个node
//         ListNode* next = cur->next; //始终指向下一个node
//         while (next != nullptr) {
//             if (next->val == cur->val) {    //如何值相等 next向后遍历
//                 next = next->next;
//             }else {                         //如果不相等 把cur的next指向next的node
//                 cur->next = next;   
//                 cur = next;
//                 next = next->next;
//             }
//         }
//         cur->next = next;       //如果是2 2 2 2 2 2 2 2 2
//         return head;
//     }
// };