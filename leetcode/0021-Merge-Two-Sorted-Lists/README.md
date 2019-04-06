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
