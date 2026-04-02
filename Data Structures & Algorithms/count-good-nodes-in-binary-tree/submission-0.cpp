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
public:

    void aux(TreeNode *r, int max, int &cnt) {
        if (!r)
            return;
        
        if (r->val >= max) {
            max = r->val;
            cnt += 1;
        }

        aux(r->left, max, cnt);
        aux(r->right, max, cnt);
    }

    int goodNodes(TreeNode* root) {
        int cnt = 0;

        aux(root, root->val, cnt);

        return cnt;
    }
};
