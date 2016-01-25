#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL) return NULL;
        ListNode* lowHead = new ListNode(-1);
        ListNode* upHead = new ListNode(-1);
        ListNode *pre1 = lowHead;
        ListNode *pre2 = upHead;

        for (ListNode* p=head; p!=NULL; p=p->next)
        {
            if (p->val < x)
            {
                pre1->next = p;
                pre1 = p;
            }
            else
            {
                pre2->next = p;
                pre2 = p;
            }
        }

        pre1->next = upHead->next;
        pre2->next = NULL;

        return lowHead->next;
    }
};
