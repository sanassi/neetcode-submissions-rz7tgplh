/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
  void aux(TreeNode *t, int d, int &max) {
    if (!t) {
      max = std::max(d, max);
      return;
    }

    aux(t->left, d + 1, max);
    aux(t->right, d + 1, max);
  }

public:
  int maxDepth(TreeNode *root) {
    int max = 0;
    aux(root, 0, max);

    return max;
  }
};