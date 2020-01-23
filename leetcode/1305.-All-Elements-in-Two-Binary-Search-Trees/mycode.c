/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sorted[10000];
int sp;

int comp(const void*a, const void*b){
  return *(int*)a - *(int*)b;
}

void inorder_travel(struct TreeNode* node){
  if(!node){
    return;
  }
  inorder_travel(node->left);
  sorted[sp++] = node->val;
  inorder_travel(node->right);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){

  sp = 0;
  inorder_travel(root1);
  inorder_travel(root2);
  *returnSize = sp;
  qsort(sorted, sp, sizeof(int), comp);
  return sorted;
}

// 196 ms(83.33%)
// 57.7 MB
// https://leetcode.com/contest/weekly-contest-169/submissions/detail/289366445/
