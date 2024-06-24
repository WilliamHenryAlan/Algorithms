class Solution {
public:
    ListNode* deleteDuplicates(ListNode* cur) {
        if (!cur) return nullptr;
        ListNode* dummy = new ListNode(-1,cur);
        cur = dummy;
        while (cur->next and cur->next->next) {
            if (cur->next->val == cur->next->next->val) { //有node的value相等
                int temp = cur->next->val;//store value
                while (cur->next and cur->next->val == temp) {//如果value相等 逐个delete
                    cur->next = cur->next->next;
                }
            }else {
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
