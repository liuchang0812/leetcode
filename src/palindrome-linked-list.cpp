/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> S;
        ListNode* root = head;
        while (root != NULL)
        {
            S.push(root->val);
            root = root->next;
        }
        root = head;
        while (root != NULL)
        {
            if (S.top() == root->val)
            {
                S.pop();
                root = root->next;
            }
            else
                return false;
        }
        return true;
    }
};
