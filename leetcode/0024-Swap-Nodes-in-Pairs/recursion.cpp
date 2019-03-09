/**
 * Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * Example:
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * solution: https://leetcode.com/explore/learn/card/recursion-i/250/principle-of-recursion/1681/discuss/248445/C++-100-4ms-using-recursionhttps://leetcode.com/explore/learn/card/recursion-i/250/principle-of-recursion/1681/discuss/248445/C++-100-4ms-using-recursion
 */
struct ListNode {
 int val;
 struct ListNode *next;
};
ListNode* swapPairs(ListNode* head) {
	if (!head || !head->next) return head; //if the next two nodes are : something->null or just null : need no swap
	ListNode* second = head->next;
	ListNode* temp = second->next;
	second->next = head;
	head->next = swapPairs(temp);
	return second;
}
