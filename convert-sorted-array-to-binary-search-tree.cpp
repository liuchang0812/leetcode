class Solution {
public:
    void dfs(int left, int right, TreeNode* &root, vector<int>& num)
    {
        if (left >= right) return ;
        int mid = left + (right - left) / 2;
        root = new TreeNode(num[mid]);
        dfs(left, mid, root->left,num);
        dfs(mid+1, right, root->right,num);
    }

    TreeNode* sortedArrayToBST(vector<int>& num) {
        TreeNode* root = NULL;
        dfs(0, num.size(), root, num);
        return root;
    }
};
