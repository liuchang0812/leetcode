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
    map<TreeNode*, int> maxSum2leaf;
    int ans;
    int dfs(TreeNode* root)
    {
        if (root==NULL) return 0;
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        int v = root->val + max(0, max(left, right));
        maxSum2leaf[root] = v;
        return v;
    }
    
    void get(TreeNode* root)
    {
        if (root==NULL) return;
        
        int sum = root->val;
        if (root->left) sum = max(sum, sum + maxSum2leaf[root->left]);
        if (root->right) sum = max(sum, sum + maxSum2leaf[root->right]);
        
        ans = max(sum, ans);
        get(root->left);
        get(root->right);
        return;
    }
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
        dfs( root);
        get(root);
        return ans;
    }
};
