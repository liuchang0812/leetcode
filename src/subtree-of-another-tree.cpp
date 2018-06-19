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
    bool isSameTree(TreeNode* s, TreeNode* t) {
	    if (s == NULL && t == NULL) return true;
	    else {
		    if (s == NULL || t == NULL) return false;
		    return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
	    }
    } 

    bool isSubtree(TreeNode* s, TreeNode* t) {
	    if (s == NULL && t == NULL) return true;
	    else if (s == NULL) return false;

	    if (isSameTree(s, t)) return true;
	    else {
		return isSubtree(s->left, t) || isSubtree(s->right, t);
	    }
    }
};
