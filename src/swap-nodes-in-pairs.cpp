#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printlist(ListNode* head)
{
    while (head != NULL)
    {
        cout << head->val << "->" ; 
        head = head->next;
    }
    cout << endl;
}

char c;
class Solution {
public:
    ListNode* swapBlock(ListNode* &head){
        // head -> ( node1, node2)
        if (head == NULL) return NULL; 
        ListNode* ln1 = head->next;
        if (ln1 == NULL) return NULL;
        ListNode* ln2 = head->next->next;
        if (ln2 == NULL) return NULL;

        ListNode* tmp = ln2->next;
        ln1->next = tmp;
        ln2->next = ln1;

        head->next = ln2;
        return ln1;
    }
    
    ListNode *swapPairs(ListNode *head) {
        ListNode *ln1, *ln2, *ans = new ListNode(0);
        ans->next = head;
        bool first = true;
        ListNode *ptr;
        while (true)
        {
            printlist(ans);
            if (first){
                first = false;
                ptr = swapBlock(ans);
            }
            else
                ptr = swapBlock(ptr);
            if (ptr == NULL) return ans->next;
        }
    }
};

void test() {
    ListNode* head = new ListNode(1);
    ListNode* ptr = head;
    for(int i=2; i<8; i++)
    {
        ptr->next = new ListNode(i);
        ptr = ptr->next;
    }
    Solution s;
    s.swapPairs(head);
}

int main()
{
    test();
    return 0;
}

    
