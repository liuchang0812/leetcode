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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *ans, *cur;
        ans = new ListNode(0);
        cur = ans;
        while (l1!=NULL && l2!=NULL)
        {
            ListNode *tmp = new ListNode(min(l1->val, l2->val));
            if (l1->val <= l2->val)
            {
                l1 = l1->next;
            }
            else 
            {
                l2 = l2->next;
            }
            cur->next = tmp;
            cur = cur->next;
        }
        while (l1!=NULL)
        {
            ListNode* tmp = new ListNode(l1->val);
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
        }
        
        while (l2!=NULL)
        {
            ListNode* tmp = new ListNode(l2->val);
            cur->next = tmp;
            cur = cur->next;
            l2 = l2->next;
        }
        return ans->next;
    }
};
