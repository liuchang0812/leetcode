#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* get(ListNode* head, int len)
    {
        if (head == NULL || len <= 0) 
            return NULL;
        
        cout << head->val << ' ' << len << endl;
        int mid = len / 2 + 1;
        ListNode *midNode;
        midNode = head;
        for(size_t i=1; i<mid; ++i)
            midNode = midNode->next;
            
        TreeNode* root = new TreeNode(midNode->val);
        TreeNode* left = get(head, mid-1);
        TreeNode* right = get(midNode->next, len-mid);
        root->left = left;
        root->right = right;
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int len = 0;
        for(ListNode* p=head; p!=NULL; p=p->next)
            len++;

        return get(head, len);
    }
};


int main()
{
    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    for (int i=0; i<5; ++i)
    {
        p->next = new ListNode(i);
        p = p->next;
    }
    Solution().sortedListToBST(dummy->next);
    return 0;
}
