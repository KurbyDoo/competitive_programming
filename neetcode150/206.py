# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        past, n = None, head

        while n:
            temp = n.next
            n.next = past
            past = n
            n = temp

        return past
