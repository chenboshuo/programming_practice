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
  struct ListNode *next1 = l1->next;
  struct ListNode *next2 = l2 -> next;

  if(!next1 && !next2){
    return NULL;
  }else if (next1 && !next2) {
    return next1;
  }else if (!next1 && next2){
    return next2;
  }

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

// Your input
// [1,2,4]
// [1,3,4]
// Output
// [1,1,2,3]
// Expected
// [1,1,2,3,4,4]
