/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <cstddef>
struct ListNode {
  int val;
  struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
  if(!l1 && !l2){
    return NULL;
  }else if(!l1 && l2){
    return l2;
  }else if(l1 && !l2){
    return l1;
  }
    struct ListNode *next1 = l1->next;
    struct ListNode *next2 = l2 -> next;

  if(l1->val <= l2->val){
    l1->next = l2;
    l2->next = mergeTwoLists(next1, next2);
    return l1;
  }else{
    l2->next = l1;
    l1->next = mergeTwoLists(next1, next2);
    return l2;
  }
}

// https://leetcode.com/submissions/detail/216511959/
// Input:
// [5]
// [1,2,4]
// Output:
// [1,5,2,4]
// Expected:
// [1,2,4,5]
