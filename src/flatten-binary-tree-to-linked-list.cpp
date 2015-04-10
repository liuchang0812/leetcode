class Solution {
public:
    vector<TreeNode*> nodes;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        else
        {
            nodes.push_back(root);
            dfs(root->left);
            dfs(root->right);
        }            
    }          
    void flatten(TreeNode *root) {
        if (root == NULL) return;
        nodes.clear();
        dfs(root);
        for (int i = 0;i < nodes.size() - 1; ++ i)
        {
            nodes[i]->right = nodes[i+1];
            nodes[i]->left = NULL;
        }
        if (nodes.size() > 0) {
            nodes[nodes.size()-1]->left = NULL;
            nodes[nodes.size()-1]->right = NULL;
        }
    }                                
};          
