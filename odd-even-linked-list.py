from typing import List

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def oddEvenList(self, head: ListNode) -> ListNode:
        if head == None:
            return None
        else:
            odd_head = head
            even_head = head.next
            odd_tail = odd_head
            even_tail = even_head
            while (even_tail != None and even_tail.next != None):
                odd_tail.next = even_tail.next
                odd_tail = odd_tail.next
                even_tail.next = odd_tail.next
                even_tail = even_tail.next
            odd_tail.next = even_head
            return odd_head
