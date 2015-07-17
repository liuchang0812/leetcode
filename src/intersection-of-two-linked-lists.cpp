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
    void lengthAndTail(ListNode *head, int &len, ListNode* &tail) {
        len = 0;
        tail = head;
        while (head != NULL) {
            len ++;
            head = head->next;
            if (head!=NULL) tail = head;
        }
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA, lenB;
        ListNode *hA, *hB;
        hA = headA, hB = headB;
        
        ListNode *tailA, *tailB;
        
        lengthAndTail(hA, lenA, tailA);
        lengthAndTail(hB, lenB, tailB);
        
        if (tailA != tailB)
            return NULL;
        
        int diff = abs(lenA-lenB);
        if (lenA > lenB) {
            for(int i = 0;i < diff; ++i) hA = hA->next;
        }
        else {
            for (int i = 0;i < diff; ++i) hB = hB->next;
        }
        
        while( hA!=hB)
            hA=hA->next, hB=hB->next;
            
        return hA;
        }
};
