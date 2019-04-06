21. Merge Two Sorted Lists
Easy

2006

279

Favorite

Share
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:
```
Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```

[原题](https://leetcode.com/problems/swap-nodes-in-pairs/)

## 思路
将l1设为返回的链表,l2视为比较对象, 要是l1的下一个比l2小,直接进行下一次操作.

否则,将l2视为主链,判断l1与l2下一个的大小,直到l1没有下一个

这时候吧l2接到后面

其他人的解法
```py
# iteratively
def mergeTwoLists1(self, l1, l2):
    dummy = cur = ListNode(0)
    while l1 and l2:
        if l1.val < l2.val:
            cur.next = l1
            l1 = l1.next
        else:
            cur.next = l2
            l2 = l2.next
        cur = cur.next
    cur.next = l1 or l2
    return dummy.next

# recursively    
def mergeTwoLists2(self, l1, l2):
    if not l1 or not l2:
        return l1 or l2
    if l1.val < l2.val:
        l1.next = self.mergeTwoLists(l1.next, l2)
        return l1
    else:
        l2.next = self.mergeTwoLists(l1, l2.next)
        return l2

# in-place, iteratively        
def mergeTwoLists(self, l1, l2):
    if None in (l1, l2):
        return l1 or l2
    dummy = cur = ListNode(0)
    dummy.next = l1
    while l1 and l2:
        if l1.val < l2.val:
            l1 = l1.next
        else:
            nxt = cur.next
            cur.next = l2
            tmp = l2.next
            l2.next = nxt
            l2 = tmp
        cur = cur.next
    cur.next = l1 or l2
    return dummy.next
```
[原文python solutions (iteratively, recursively, iteratively in-place).](https://leetcode.com/problems/merge-two-sorted-lists/discuss/9735/Python-solutions-(iteratively-recursively-iteratively-in-place).)
