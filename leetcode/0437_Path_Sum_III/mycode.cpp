#include<unordered_map>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  int pathSum(TreeNode *root, int sum) {
    record_sum(root);

    return sums[sum];
  }
 private:
  unordered_map<int,int> sums;
  void record_sum(TreeNode *node){
    if(!node){
      return 0;
    }
    int left = record_sum(node->left);
    int right = record_sum(node->right);
    int parent = node->val;
    sums[parent] += 1;
    sums[parent+left] += (left != 0);
    sums[parent+right] += (right != 0);
    sums[parent+left+right] += (right != 0 && left != 0);
    return parent;
  }
};
