class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 or head == nullptr or head->next == nullptr) {
            return head;
        }
        int n = 1;
        ListNode* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
            n++;
        }
        int add = n - k % n;
        if (add == n) {
            return head;
        }
        temp->next = head;
        while (add--) {
            temp = temp->next;
        }
        ListNode* ans = temp->next;
        temp->next = nullptr;
        return ans;
    }
};
