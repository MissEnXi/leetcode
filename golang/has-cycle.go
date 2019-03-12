/*
给定一个链表，判断链表中是否有环。
*/

package golang

type ListNode struct {
	val  int
	next *ListNode
}

func hasCycle(head *ListNode) bool {
	fast, slow := head, head
	for fast != nil && slow != nil && fast.next != nil {
		slow = slow.next
		fast = fast.next.next
		if slow == fast {
			return true
		}
	}

	return false
}
