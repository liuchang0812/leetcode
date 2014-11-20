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
    ListNode *insertionSortList(ListNode *head) {
        if (Length(head) < 2) return head;
        ListNode* ans;
        ans = new ListNode(0);
        for (ListNode *p = head; p !=NULL; p=p->next)
        {
            Insert(ans, p->val);
        }
        return ans->next;
    }
private:
    int Length(ListNode* head)
    {
        int ans = 0;
        while (head!=NULL)
        {
            ans ++;
            head = head->next;
        }
        return ans;
    }
    void Insert(ListNode* head, int val)
    {
        ListNode* tmp = new ListNode(val);
        ListNode* pre = head;
        for (ListNode *p = head->next; p!=NULL; p=p->next)
        {
            if (p->val >= val)
            {
                pre->next = tmp;
                tmp->next = p;
                return;
            }
            pre = p;
        }
        pre->next = tmp;
    }
};
