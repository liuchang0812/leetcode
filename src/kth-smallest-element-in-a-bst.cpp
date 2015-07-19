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
    int ans = -1;
    int index = 0;
    
    void dfsIter(TreeNode* cur, int k)
    {
        if (cur == NULL) return;
        
        dfsIter(cur->left, k );
        index ++;
        if (index <= k)
            ans = cur->val;
        if (index < k)
            dfsIter(cur->right, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        dfsIter(root,k);
        return ans;
    }
    
};
