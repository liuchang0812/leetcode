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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL || head->next->next == NULL) return head;

        ListNode* dummyHead = new ListNode(-1); dummyHead->next = head;        
        ListNode* dummySnd = new ListNode(-1); dummySnd->next = head->next;


        ListNode *i, *j;
        ListNode *prei, *prej;
        prei = dummyHead; prej = dummySnd;

        i = head; j = head->next;
        for(; i!=NULL && j!=NULL; )
        {
            prei->next = i;
            prej->next = j;

            prei = i;
            prej = j;

            i = j->next;
            if (i!=NULL)
                j = i->next;
            else 
                j = NULL;
        }

        if (i!=NULL)
        {
            prei->next = i;
            i->next = dummySnd->next;
        }
        else
        {
            prei->next = dummySnd->next;
        }
        prej->next = j;

        return dummyHead->next;
    }
};
