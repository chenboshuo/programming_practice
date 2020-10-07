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
  if (!head) { return NULL; }
  struct ListNode *slow = head, *fast = head;
  while (k) {
    while (k && fast) {
      fast = fast->next;
      --k;
    }
    if (!fast) { fast = head; }
  }
  struct ListNode *pre_slow = slow, *pre_fast = fast;
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
//
// Input:
// [1]
// 0
// Output:
// []
// Expected:
// [1]
