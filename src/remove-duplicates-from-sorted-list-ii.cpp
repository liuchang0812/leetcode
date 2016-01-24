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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> cnt;
        for(ListNode* p=head; p!=NULL; p=p->next)
        {
            cnt[p->val] ++;
        }
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        
        ListNode* pre = dummyHead;
        
        int hasHead = false;
        for (ListNode* p=head; p!=NULL;)
        {
            if(cnt[p->val]>1)
            {
                pre->next = p->next;
                p = p->next;
            }
            else
            {
                if (!hasHead)
                {
                  hasHead = true;
                  dummyHead->next = p;
                }
                pre = p;
                p = p->next;
            }
            if (!hasHead) dummyHead->next = NULL;
        }
        return dummyHead->next;
    }
};
