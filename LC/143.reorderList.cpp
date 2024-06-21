class Solution {
public:
    ListNode* reverseList(ListNode* cur) {
        ListNode* nxt = nullptr,*prev = nullptr;
        while (cur) {
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head,*fast = head;
        while (fast and fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
    void reorderList(ListNode* head) {
        ListNode* ret = head;//non-return ,暂存head
        ListNode* middle = middleNode(head);//get middle node
        ListNode* end = reverseList(middle);//reverse the latter half list
        while (end->next) { //reorder
            ListNode* tempHead = head->next,*tempEnd = end->next;
            head->next = end;
            end->next = tempHead;
            head = tempHead;
            end = tempEnd;
        }
        head = ret;
    }
};