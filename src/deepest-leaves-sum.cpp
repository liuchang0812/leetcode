/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int, vector<int> > leaves;
    int max_deep = 1;
    void dfs(TreeNode* root, int deep) {
        if (root->left == NULL && root->right == NULL) {
            leaves[deep].push_back(root->val);
            max_deep = max(max_deep, deep);
        }else {
            if (root->left) dfs(root->left, deep+1);
            if (root->right) dfs(root->right, deep+1);
        }
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 1);
        return std::accumulate(leaves[max_deep].begin(), leaves[max_deep].end(), 0);

    }
};
