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
    void dfs(ListNode* prev, ListNode* cur, int val)
    {
        if (cur == NULL) return;
        
        if (cur->val != val)
            dfs(cur, cur->next, val);
        else
        {
            prev->next = cur->next;
            dfs(prev, cur->next, val);
        }
    }
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p_head = new ListNode(-1);
        p_head->next = head;
        
        dfs(p_head, head, val);
        return p_head->next;
    }
};
