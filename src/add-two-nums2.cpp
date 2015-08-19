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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode(-1);
        ListNode* cur = pre;
        int n = 0;
        while (l1 || l2 || n)
        {
            int v = n + (l1?l1->val:0) + (l2?l2->val:0);
            n = v / 10;
            v %= 10;
            
            ListNode* tmp = new ListNode(v);
            cur->next = tmp;
            cur = tmp;
            if(l1)l1 = l1->next;
            if(l2)l2 = l2->next;
        }
        
        return pre->next;
    }
};
