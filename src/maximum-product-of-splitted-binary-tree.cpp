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
    void dfs(TreeNode* root, long long& _sum) {
        if (root) {
            _sum += root->val;
            dfs(root->left, _sum);
            dfs(root->right, _sum);
        }
    }
    
    long long dfs2(TreeNode* root, long long _sum, long long& ans) {
        if (root) {
            long long _sum_left = dfs2(root->left, _sum, ans);
            long long _sum_right = dfs2(root->right, _sum, ans);
            long long _sum_sub_tree = _sum_left + _sum_right + root->val;

            
            ans = max(ans, ((_sum_sub_tree * (_sum - _sum_sub_tree))));
            
            return _sum_sub_tree;
        }else 
            return 0;
    }
    
    int maxProduct(TreeNode* root) {
        long long _sum = 0;
        dfs(root, _sum);
        //cout << _sum << endl;
        long long ans = 0;
        dfs2(root, _sum, ans);
        return ans  % 1000000007;
    }
};
