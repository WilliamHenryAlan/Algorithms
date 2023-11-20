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
1.设置三个指针 current用于指向当前节点 
因为单链表无法找到前节点 所以设置prev指向前项节点 逆置链表会丢失下一节点 所以next指向后项节点
2.因为逆置尾节点最后指向nullptr 所以一开始prev初始化为nullptr
3.每次遍历 先把next指向current的后面一个节点 这样就可以断开current的节点 完成逆置
4.逆置完成之后 需要把prev = current之后再迭代current
5.循环结束 需要把头节点指向prev指针 并完成return
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* cur = head,*next = nullptr,*prev = nullptr;
        while (cur != nullptr)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
        return head;
        
    }
};

int main()
{
    
}