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

#include <algorithm>
#include <cstdlib>
#include <utility>

class Solution {
public:
  // (depth, balanced)
  std::pair<int, bool> aux(TreeNode *t) {
    if (!t) {
      return {0, true};
    }

    const auto l = aux(t->left);
    const auto r = aux(t->right);

    if (std::abs(l.first - r.first) > 1) {
      return {0, false};
    }

    return {1 + std::max(l.first, r.first), l.second && r.second};
  }
  bool isBalanced(TreeNode *root) { return aux(root).second; }
};