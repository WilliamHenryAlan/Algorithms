#include <iostream>
#include <stack>
struct ListNode {
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr) {}
    ListNode(int val):val(val),next(nullptr) {}
    ListNode(int val,ListNode* next):val(val),next(next) {}
};

/*

给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
示例 1：

输入：head = [1,2,2,1]
输出：true

示例 2：

输入：head = [1,2]
输出：false

*/

/*
用stack进行反转
*/


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::stack<int> st;
        ListNode* temp = head;
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }
        while (head != nullptr) {
            if (st.top() == head->val) {
                st.pop();
            }else {
                return false;
            }
            head = head->next;
        }
        return true;
    }
};