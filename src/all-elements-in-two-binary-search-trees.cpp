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
    void dfs(TreeNode* root1, vector<int>& vi) {
        if (root1) {
            dfs(root1->left, vi);
            vi.push_back(root1->val);
            dfs(root1->right, vi);
        }
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        dfs(root1, ans);
        dfs(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
