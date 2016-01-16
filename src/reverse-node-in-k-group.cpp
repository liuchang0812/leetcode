#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        
        ListNode *front, *end;

        front = dummyHead;
        end = NULL;

        int cur = 0;
        bool isFirst = true;
        for (ListNode* p = head; p!=NULL;)
        {
 
    for(ListNode* p=dummyHead->next; p!=NULL; p=p->next)
    {

        cout << p->val << "->";
    }
    cout << endl;
              cerr << p->val << endl;
            cur ++;
            if (cur == k)
            {
                cerr << "begin reverse " << endl;
                //reverse k nodes
                end = p->next;

                ListNode* h = front->next;
                ListNode* next = h->next;
                
                while (next != end)
                {
                    cerr <<"front " << front->val <<  " h " << h->val <<" next " << next->val << endl;
                    ListNode* dummy_next = next->next;
                    next->next = h;
                    h = next;
                    next = dummy_next;
                }

                front->next->next = end;
                ListNode* tmp = front->next;
                front->next = h; 
                front = tmp;
                if (isFirst) {
                    isFirst = false;
                    dummyHead->next = p;
                    }
                p = end;
                cur = 0;
                }
            else
                p = p->next;
        }
        return dummyHead->next;
    }
};


int main()
{


    vector<ListNode*> nodes;
    for (int i = 1; i <= 5; i++)
    {
        ListNode* node = new ListNode(i);
        nodes.push_back(node);
    }

    for (int i = 0; i < 4; i++)
        nodes[i]->next = nodes[i+1];

    ListNode* ans = Solution().reverseKGroup(nodes[0], 3);

    for(ListNode* p=ans; p!=NULL; p=p->next)
    {

        cout << p->val << "->";
    }
    cout << endl;
    return 0;
}
