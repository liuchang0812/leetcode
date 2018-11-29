class Solution {
public:

    void dfs(TreeNode* root, TreeNode** trueRoot) {
        if (root == nullptr) return;
        cout << "try: " << root->val << endl;
        
        dfs(root->left, trueRoot);
        (*trueRoot)->left = nullptr;
        (*trueRoot)->right = root;
        
        cout << "ele: " << root->val << ' ' << (*trueRoot)->val<< endl;

        *trueRoot = root;

        dfs(root->right, trueRoot);
        (*trueRoot)->left = nullptr;
        (*trueRoot)->right = nullptr;
    }
    TreeNode* increasingBST(TreeNode* root) {
        TreeNode node(-1);
        TreeNode* p = &node;
        TreeNode** p2 = &p;
        dfs(root, p2);
        return node.right;
    }
};
