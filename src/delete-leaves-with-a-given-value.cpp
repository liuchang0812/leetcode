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
    bool dfs(TreeNode* root, int target) {
        if (root==NULL) return true;
        bool deleteLeft = dfs(root->left, target);
        bool deleteRight = dfs(root->right, target);
        if (deleteLeft) root->left = NULL;
        if (deleteRight) root->right = NULL;
        if (root->val == target && deleteLeft && deleteRight) {
            return true;
        } else return false;
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        bool b = dfs(root, target);
        if (b) return NULL;
        else return root;
    }
};
