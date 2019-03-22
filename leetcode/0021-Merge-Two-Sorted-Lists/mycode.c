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

    struct ListNode *next1 = l1 -> next;
    struct ListNode *next2 = l2 -> next;
    if(!next1) next1 = &l1;
    if(!next2) next2 = &l2;

    if(l1->val <= l2->val){
        if(l2 -> val <= next1 -> val){
            l1 -> next = l2;
        }else{
            l1 -> next = mergeTwoLists(next1,l2);
        }
        return l1;
    }else{
        if(l1 -> val >= next2 -> val){
            l2 -> next = mergeTwoLists(l1,next2);
        }else{
            l2 -> next = l1;
        }
        return l2;
    }
}

// Finished
// Runtime: 4 ms
// Your input
// [5]
// [1,3,4]
// Output
// [1,3,4,5]
// Expected
// [1,3,4,5]

// Wrong Answer
// https://leetcode.com/submissions/detail/216759209/
// Details
// Input
// [1,2,4]
// [1,3,4]
// Output
// [1,1,3,4]
// Expected
// [1,1,2,3,4,4]
