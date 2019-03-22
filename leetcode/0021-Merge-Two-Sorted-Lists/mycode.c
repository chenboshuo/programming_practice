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


    if(l1->val <= l2->val){
        if(l2 <= next1){
            l1 -> next = l2;
        }else{
            l1 -> next = mergeTwoLists(next1,l2);
        }
        return l1;
    }else{
        if(l1 <= next2){
            l2 -> next = l1;
        }else{
             l2 -> next = mergeTwoLists(l1,next2);
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
// [1,5]
// Expected
// [1,3,4,5]
