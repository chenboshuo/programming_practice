/**
 * Swap Nodes in Pairs
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * You may not modify the values in the list's nodes, only nodes itself may be changed.
 * Example:
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 */
struct ListNode {
     int val;
     struct ListNode *next;
 };
struct ListNode* swapPairs(struct ListNode* head) {
  if(!head->next->next){
    return 0;
  }
  struct ListNode* new_next = head->next->next;
  head->next->next = &head;
  head->next = new_next;
  swapPairs(head->next);
}
