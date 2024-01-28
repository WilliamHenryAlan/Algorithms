#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
Method 1:array
1.因为LinkedList不能实现随机访问 把LinkedList映射到vector中
tips：
1.题目要求偶数node时 返回第二个node 所以直接return数组大小的一半的index即可
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> a;
        while (head != nullptr) {
            a.push_back(head);
            head = head->next;
        }
        return a[a.size()/2];
    }
};
/*
Method 2:single pointer
1.遍历LinkedList两次 第一次计数node数量 第二次 遍历到1/2位置并return 这样空间复杂度达到O(1)
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            size++;
            temp = temp->next;
        }
        temp = head;
        size /= 2;
        while (size != 0) {
            temp = temp->next;
            size--;
        }
        return temp;
    }
};

/*
Method 3:快慢指针
1.slow和fast指向head
2.slow每次1步 fast两步 fast == nullptr 时 slow指向的就是middle node

*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head,*fast = head;
        while (fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
/*
practice:2024.1.28
*/
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* slow = head, *fast = head;
        while (fast != nullptr and fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};