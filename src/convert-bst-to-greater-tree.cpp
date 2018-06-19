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
    int dfs(TreeNode* root, int plus) {
       
        if (root == NULL) return plus;
        //cout << root->val << ' ' << plus << endl;
        int v = dfs(root->right, plus);
        //cout <<"right "<< v << ' ' << plus << endl;
        root->val = root->val + v;
        int v2 = dfs(root->left, root->val);
        return v2;
    }
    
    TreeNode* convertBST(TreeNode* root) {
        dfs(root, 0);
        return root;
    }
};
