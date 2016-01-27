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
    TreeNode* get(const vector<int>& preorder, int b, int e, const vector<int>& inorder, int b2, int e2)
    {
        cout << " b1 e1 b2 e2 " << b << ' ' << e << ' ' << b2 << ' ' << e2 << endl;
        if (e <= b) return NULL;
        
        TreeNode* head = new TreeNode(preorder[b]);
        
        int mid;
        for (int i=b2; i<e2; ++i)
            if (inorder[i] == preorder[b])
            {
                mid = i;
                break;
            }
        mid -= b2;
        
        TreeNode* left = get(preorder, b+1, b+mid+1, inorder, b2, b2+mid);
        TreeNode* right = get(preorder, b+mid+1, e, inorder, b2+mid+1, e2);
        head->left = left;
        head->right = right;
        return head;
        
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return get(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }
};
