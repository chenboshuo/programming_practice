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
  if (!head) { return head; }
  struct ListNode *fast = head, *pre_fast = head;

  // get the length of linked list
  int length = 0;
  for (struct ListNode *i = head; i; i = i->next) { ++length; }
  k %= length;
  if (k == 0) { return head; }

  // find the new head
  while (k-- > 0) {
    pre_fast = fast;
    fast = fast->next;
  }
  struct ListNode *slow = head, *pre_slow = NULL;
  while (fast) {
    pre_slow = slow;
    pre_fast = fast;
    fast = fast->next;
    slow = slow->next;
  }
  if (pre_slow) {
    pre_fast->next = head;
    pre_slow->next = NULL;
  }
  return slow;
}

// 231 / 231 test cases passed.
// Status: Accepted
// Runtime: 4 ms
// Memory Usage: 6.1 MB
// Submitted: 0 minutes ago
