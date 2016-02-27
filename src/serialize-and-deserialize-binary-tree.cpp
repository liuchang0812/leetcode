#include <iostream>
#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    string itoa(int x)
    {
        if (x == 0) return "0";
        else
        {
            string ret;
            while (x)
            {
                ret = char('0' + (x % 10)) + ret;
                x /= 10;
            }
            return ret;
        }
    }

    int atoi(string& s, int l, int r)
    {
        int ret = 0;
        for (int i=l; i<= r; ++i)
            ret = ret * 10 + s[i] - '0';
        return ret;
    }

    // Encodes a tree to a single string.
    string dfs1(TreeNode* root)
    {
        if (root == NULL)
            return "()";
        else
        {
            string lt = dfs1(root->left);
            string rt = dfs1(root->right);
            return "(" + itoa(root->val) + lt + rt + ")";
        }
    }

    string serialize(TreeNode* root) {
        return dfs1(root);
    }

    TreeNode* dfs2(string& data, int l, int r)
    {
        cout << "dfs2 " << l << ' ' << r << endl;
        if (r <= l+1)
            return NULL;
        int numL = 0;
        for (int i=l; i<=r; i++)
            if (data[i] == '(') numL++;

        if (numL == 1)
        {
            return new TreeNode(atoi(data, l+1, r-1));
        }
        else
        {
           int pos = l + 1;
           int l1, r1;
           l1 = pos;
           while (data[l1] != '(') l1++;
           pos = l1 + 1;
           int tmp = 1;
           while (tmp){
               if (data[pos] == '(') tmp ++;
               else if (data[pos] == ')') tmp --;
               pos ++;
           }
           r1 = pos - 1;

           TreeNode* leftTree = dfs2(data,  l1, r1);
           TreeNode* rightTree = dfs2(data, r1+1, r-1);

           TreeNode* r = new TreeNode(atoi(data, l+1, l1-1));
           r->left = leftTree;
           r->right = rightTree;
           return r;
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return dfs2(data, 0, data.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//
int main()
{
    string inp = "(1(2)(3))";
    
    TreeNode* root = Codec().deserialize(inp);    
    cout << root->val << endl;
    cout << root->left->val << endl;
    cout << root->right->val << endl;
    cout << Codec().serialize(root) << endl;
    return 0;
}
