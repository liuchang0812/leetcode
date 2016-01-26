#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (m >= n) return head;
        ListNode* dummyHead = new ListNode(-1); 
        dummyHead->next = head;
        int cur = 1;
        ListNode *mHead, *nHead, *mPreHead;
        ListNode *pre = dummyHead;
        for (ListNode* p=head; p!=NULL; p=p->next, pre=pre->next)
        {
            if (cur == m)
            {
                mPreHead = pre;
                mHead = p;
            }
            if (cur == n)
            {
                nHead = p;
                break;
            }
            cur ++;
        }
        
        // reverse
        ListNode *p1, *p2;
        p1 = mHead;
        p2 = mHead->next;

        while (p1!=nHead)
        {
            ListNode* tmp = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = tmp;
        }

        ListNode* tmp = mPreHead->next;
        tmp->next = p2;
        mPreHead->next = p1;

        return dummyHead->next;
    }
};
