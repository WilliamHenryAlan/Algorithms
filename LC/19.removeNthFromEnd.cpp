/*
2023.12.18

issue：
删除单链表中倒数第n个元素

solution：
因为单链表不能逆向寻找 所以删除倒数节点用双指针的方式
1.slow指针指向head 
2.fast指针向后遍历n次 如果遍历到nullptr 说明n非法 则return
3.这样slow和fast之间夹着的就是n
4.保持fast和slow的距离 同时向后后遍历
5.知道fast指向nullptr 说明slow指向了倒数第n个结点
6.因为slow指向了倒数第n个结点 如果直接删除会断开上一结点的链接
因此 单链表的删除操作应该寻找上一结点 所以2步骤应该再多移动一次
但是这样又回出现问题 当链表只有两个元素 要删除倒数第一个元素时
fast会向后遍历两次 会指向nullptr 根据判断条件满足 会判断n值非法 所以return 但是实际上倒数第一个元素是存在的
所以更为好的方式是 在4步骤 fast->next == nullptr情况下 slow停止 fast单独再向后遍历一个node
7.考虑到删除第一个node的情况 会创建一个dummy结点 方便删除操作

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
        //create dummy node
        ListNode* dummy = new ListNode;
        dummy->next = head;
        head = dummy;
        //move fast
        ListNode* fast = head,* slow = head;
        while (n-- && fast != nullptr) {
            fast = fast->next;
        }
        //n值非法
        if (fast == nullptr) {
            head = dummy->next;
            delete dummy;
            return head;
        }
        //保持fast和slow的间距向后遍历 注意遍历条件
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
        //fast = fast->next;    //这条代码按步骤应该写 但是写不写不影响结果

        //删除node释放内存
        ListNode* release = slow->next;
        slow->next = release->next;
        delete release;

        //删除dummy node 释放内存
        head = dummy->next;
        delete dummy;
        return head;
    }
};
/*
practice:2024.1.28
tips:
1.single LinkedList 删除node 需要找到他的前一个node 
也就是要删除倒数第N个node 需要找到倒数N-1个node才能实现删除操作
2.要考虑边界情况
*/
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
/*
practice
*/
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
