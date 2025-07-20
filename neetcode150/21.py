# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: ListNode, list2: ListNode) -> ListNode:
        start = ListNode(0)
        node = start
        while list1 and list2:
            if list1.val > list2.val:
                node.next = list2
                node = node.next
                list2 = list2.next

            else:
                node.next = list1
                node = node.next
                list1 = list1.next

        node.next = list1 if list1 else list2

        return start.next
