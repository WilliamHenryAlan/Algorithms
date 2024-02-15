class Solution {
public:
    ListNode* trainingPlan(ListNode* head, int cnt) {
        ListNode* former = head,* latter = head;
        while (cnt--) {
            // 如果cnt > 链表长度 if (!former) return nullptr;
            former = former->next;
        }
        while (former != nullptr) {
            former = former->next;
            latter = latter->next;
        }
        return latter;
    }
};