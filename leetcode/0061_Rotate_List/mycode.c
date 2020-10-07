/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode *rotateRight(struct ListNode *head, int k) {
  if (!head || k == 0) { return head; }
  struct ListNode *slow = head, *fast = head;
  while (k--) {
    if (fast) {
      fast = fast->next;
    } else {
      fast = head->next;
    }
  }
  struct ListNode *pre_slow = head, *pre_fast = head;
  while (fast) {
    pre_slow = slow;
    pre_fast = fast;
    fast = fast->next;
    slow = slow->next;
  }
  pre_fast->next = head;
  pre_slow->next = NULL;
  return slow;
}
// Submission Result: Wrong Answer
// Input:
// [1,2]
// 2
// Output:
// [1]
// Expected:
// [1,2]
