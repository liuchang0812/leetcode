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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *ans, *cur;
        ans = new ListNode(0);
        cur = ans;
        int carry = 0;
        while (l1 != NULL && l2 != NULL)
        {
            ListNode* tmp = new ListNode((l1->val + l2->val + carry)%10);
            carry = (l1->val + l2->val + carry ) / 10;
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1!=NULL)
        {
            ListNode* tmp = new ListNode((carry + l1->val)%10);
            carry = (carry + l1->val) / 10;
            cur->next = tmp;
            cur = cur->next;
            l1 = l1->next;
        }
        while (l2!=NULL)
        {
            ListNode* tmp = new ListNode((carry+l2->val)%10);
            carry = (carry + l2->val) / 10;
            cur->next = tmp;
            cur = cur->next;
            l2 = l2->next;
        }
        if (carry > 0)
        {
            ListNode* tmp = new ListNode(carry);
            cur->next = tmp;
        }
        return ans->next;
    }
};
