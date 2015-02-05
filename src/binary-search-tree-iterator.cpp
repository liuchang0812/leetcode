/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> S;
    int cur_value = INT_MIN;
    
public:
    BSTIterator(TreeNode *root) {
        if (root)
            S.push(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !S.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* p = S.top();
        TreeNode* root = p;
        while (!S.empty()) {
            p = S.top(); S.pop();
            if (p->left && p->left->val > cur_value) {
                S.push(p);    
                S.push(p->left);
            }
            else if (p->right && p->right->val > cur_value)  {
                    S.push(p->right);
                cur_value = p->val;
                return p->val;
            }
            else {
                cur_value = p->val;
                return p->val;
            }
        }
        cur_value = p->val;
        return p->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
