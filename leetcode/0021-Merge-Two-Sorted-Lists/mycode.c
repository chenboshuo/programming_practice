//Definition for singly-linked list.
struct ListNode {
   int val;
   struct ListNode *next;
};



struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    if(!l1){
        return l2;
    }
    if(!l2){
        return l1;
    }
    if(l1 -> val > l2->val){
            struct ListNode* t = l1;
            l1 = l2;
            l2 = t;
    }
    struct ListNode* head = l1;
    while(l1->next){
        if(l1->next->val > l2 -> val){
            struct ListNode* t = l1->next;
            l1->next = l2;
            l1 = l2;
            l2 = t;
        }else{
            l1 = l1 -> next;
        }

    }
    l1 -> next = l2;
    return head;
}
/**
 * Runtime: 4 ms,
 * faster than 100.00% of C online submissions for Merge Two Sorted Lists.
 * Memory Usage: 7.4 MB,
 * less than 100.00% of C online submissions for Merge Two Sorted Lists.
 * https://leetcode.com/submissions/detail/220387626/
 */
