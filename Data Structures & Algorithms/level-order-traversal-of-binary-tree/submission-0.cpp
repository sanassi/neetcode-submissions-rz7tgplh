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
    using res_type = vector<vector<int>>;
    void aux(TreeNode *r, res_type& res, int d) {
        if (!r)
            return;

        if (d > res.size()) {
            res.push_back({});
        }

        res[d - 1].push_back(r->val);

        aux(r->left, res, d + 1);
        aux(r->right, res, d + 1);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        res_type res;

        aux(root, res, 1);

        return res;
    }
};
