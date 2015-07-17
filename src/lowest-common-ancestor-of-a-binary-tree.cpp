class Solution {
public:
    map<TreeNode*, TreeNode*> father;
    map<TreeNode*, int> deep;
    void dfsIter(TreeNode* _father, TreeNode* cur, int _deep)                                     
    {
        if (cur == NULL) return;
        father[cur] = _father;
        deep[cur] = _deep;
        dfsIter(cur, cur->left, _deep+1);
        dfsIter(cur, cur->right, _deep+1);
    }                                                                                            

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {                   
        TreeNode* pre = new TreeNode(-1);
        dfsIter(pre, root, 1);
        if (deep[p] < deep[q]) swap(p, q);
        while (deep[p] != deep[q])
            p = father[p];
        TreeNode* ans;
        while (p != q)
        {
            p = father[p];
            q = father[q];
        }
        return q;
    }
};
