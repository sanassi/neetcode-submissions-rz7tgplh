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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root)
            return {};

        res_type res;

        std::deque<TreeNode*> q{root};

        int count = 0;

        while (!q.empty()) {
            std::vector<int> lvl;

            // reverse loop since we push in the vector
            for (int i = q.size(); i > 0; i--) {
                TreeNode *t = q.front();
                q.pop_front();
                lvl.push_back(t->val);
                if (t->left)
                    q.push_back(t->left);
                if (t->right)
                    q.push_back(t->right);
            }      

            res.push_back(lvl);   
        }

        return res;
    }
};
