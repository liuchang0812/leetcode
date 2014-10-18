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
    int minDepth(TreeNode *root) {
        if (root == NULL) return 0;
        queue<TreeNode*> Q;
        queue<int> deep;
        int ans = 0;
        Q.push(root);
        deep.push(1);
        
        while (!Q.empty())
        {
            TreeNode* cur = Q.front(); Q.pop();
            int cur_deep = deep.front(); deep.pop();
            if ( cur->left == NULL && cur->right==NULL){ return cur_deep; }
            if ( cur->left != NULL)
            {
                Q.push(cur->left); deep.push(cur_deep+1);
            }
            if ( cur->right != NULL)
            {
                Q.push(cur->right); deep.push(cur_deep+1);
            }
        }
    }
};
