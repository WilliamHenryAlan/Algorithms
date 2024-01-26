
func reverseKGroup(head *ListNode, k int) *ListNode {
	protect := &ListNode{Val: 0,Next: head}
    dummy := protect
	for head != nil {
		end := getEnd(head,k)
		if end == nil {
			break
		}
		endNext := end.Next
		reverse(head,endNext)
		dummy.Next = end
		head.Next = endNext
		dummy = head
		head = endNext
	}
	return protect.Next
}
func getEnd(head *ListNode,k int) *ListNode{
	for head != nil {
		k--
		if k == 0 {
			return head
		}
		head = head.Next
	}
	return nil
}
func reverse(head *ListNode, endNext *ListNode) {
	prev := head
	head = head.Next
	for head != endNext {
		next := head.Next
		head.Next = prev
		prev = head
		head = next
	}
}