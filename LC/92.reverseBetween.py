# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
        
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        dummy = ListNode(next = head)
        head = dummy
        for _ in range(left - 1):
            head = head.next
        temp = head.next

        cur = temp
        prev,nxt= None,None
        for _ in range(right - left + 1):
            nxt = cur.next
            cur.next = prev
            prev = cur
            cur = nxt
        head.next = prev
        temp.next = cur

        return dummy.next