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
    TreeNode* get(const vector<int>& postorder, int b, int e, const vector<int>& inorder, int b2, int e2)
    {
        cout << " b1 e1 b2 e2 " << b << ' ' << e << ' ' << b2 << ' ' << e2 << endl;
        if (e <= b) return NULL;
        
        TreeNode* head = new TreeNode(postorder[e-1]);
        
        
        int mid;
        for (int i=b2; i<e2; ++i)
            if (inorder[i] == postorder[e-1])
            {
                mid = i;
                break;
            }
        mid -= b2;
        
        TreeNode* left = get(postorder, b, b+mid, inorder, b2, b2+mid);
        TreeNode* right = get(postorder, b+mid, e-1, inorder, b2+mid+1, e2);
        head->left = left;
        head->right = right;
        return head;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
                return get(postorder, 0, postorder.size(), inorder, 0, inorder.size());

    }
};
