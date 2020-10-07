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
  struct ListNode *fast = head, *pre_fast = head;
  while (k--) {
    if (fast) {
      pre_fast = fast;
      fast = fast->next;
    } else {
      fast = head->next;
    }
  }
  struct ListNode *slow = head, *pre_slow = NULL;
  while (fast) {
    pre_slow = slow;
    pre_fast = fast;
    fast = fast->next;
    slow = slow->next;
  }
  if(pre_slow){
    pre_fast->next = head;
    pre_slow->next = NULL;
  }
  return slow;
}
// 231 / 231 test cases passed, but took too long.
// Status: Time Limit Exceeded
