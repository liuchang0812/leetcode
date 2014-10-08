/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    int numoflev[1005];
    vector<TreeLinkNode*> ptrsoflev[1005];
    int maxlev;
    void connect(TreeLinkNode *root) {
        maxlev=-1;
        bfs(root, 0);
        for (int lev =0; i<=maxlev;i++)
            putnext(lev);
    }
private:
    void bfs(TreeLinkNode *root, int level)
    {
        maxlev = max(maxlev, level);
        if (root != NULL)
        {
            ptrsoflev[level].push_back(root);
            bfs(root->left, level+1);
            bfs(root->right, level+1);
        }
    }
    void putnext(int lev)
    {
        int len = ptrsoflev[lev].size();
        for (int i=0;i < len; i++)
        {
            if (i==len-1) ptrsoflev[lev][i].next=NULL;
            else ptrsoflev[lev][i].next = ptrsoflev[lev][i+1];
        }
    }
};
