/*
issue:
两两交换链表中结点
solution：
创建三个指针分别指向要处理的node和他的前后驱node 两两交换node
偶数个node应该两两交换完成 遇到奇数个node 最后一个node无需交换
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
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr or head->next == nullptr) return head;  //如果为empty linkedlist 或者 单个结点的链表 return head

        ListNode* temp = new ListNode(-1);  //创建dummy node 方便第一个node的操作
        temp->next = head;
        head = temp;

        ListNode* prev = head,* cur = prev->next,* next = nullptr;  //创建3个指针 分别是遍历的指针和他的前后指针
        while (cur != nullptr and cur->next != nullptr) {   //当剩下的链表为单个node或者没有要处理的node时 loop结束
            next = cur->next;   //设置next指针
            prev->next = next;  //断开prevnode的指针 指向下下个node
            cur->next = next->next; //断开currentnode的指针 指向下下个node
            next->next = cur;   //断开nextnode指针 指向currentnode
            prev = cur; //迭代prev指针
            cur = cur->next;    //迭代current指针
        }

        head = temp->next;  //释放内存
        delete temp;
        return head;
        
    }
};


/*
2023.12.20
*/

/*
solution：
相比上一个solution 用了两个pointer 思路无异
*/
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* prev = new ListNode;
        prev->next = head;
        head = prev;

        while (prev->next != nullptr && prev->next->next != nullptr) {
            ListNode* traversal = prev->next;
            prev->next = traversal->next;
            traversal->next = prev->next->next;
            prev->next->next = traversal;
            prev = traversal;
        }
        prev = head;
        head = prev->next;
        delete prev;
        return head;
    }
};