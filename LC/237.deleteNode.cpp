/*
因为题目规定删除的不是最后一个node
可以先拷贝next node value到当前node 再删除next node
*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* relase = node->next;//store the next node to be removed
        node->val = relase->val;//copy value
        node->next = relase->next;//link
        delete relase;
    }
};
