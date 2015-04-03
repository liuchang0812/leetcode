/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<int> &ans, int level)
    {
        if (root == NULL)
            return ;
        if (ans.size() >= level+1)
            ans[level] = root->val;
        else 
            ans.push_back(root->val);
        dfs(root->left, ans, level + 1);
        dfs(root->right, ans, level + 1);
    }
    
    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        dfs(root, ans, 0);
        return ans;
    }
};
