# source: https://leetcode.com/problems/merge-two-sorted-lists/discuss/9771/Simple-5-lines-Python
def mergeTwoLists(self, a, b):
    if not a or b and a.val > b.val:
        a, b = b, a
    if a:
        a.next = self.mergeTwoLists(a.next, b)
    return a
