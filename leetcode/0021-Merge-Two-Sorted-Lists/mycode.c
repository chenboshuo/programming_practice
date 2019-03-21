/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *next1 = l1->next;
    struct ListNode *next2 = l2 -> next;

    if(!next1 || !next2){
        return NULL;
    }

    if(l1->val <= l2->val){
        l1->next = &l2;
        l2->next = mergeTwoLists(next1, next2);
        return &l1;
    }else{
        l2->next = &l1;
        l1->next = mergeTwoLists(next1, next2);
        return &l2;
    }
}
