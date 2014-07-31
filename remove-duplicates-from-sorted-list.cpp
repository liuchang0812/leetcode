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
    void deleteNode(ListNode* &front, ListNode* &rear) {
	    if (front && rear)
	    {
		    front->next = rear->next;
		    rear = front->next;
	    }
    }
    ListNode *deleteDuplicates(ListNode *head) {
       ListNode *fnt, *rear; 
       if (head == NULL) return head;
       if (head->next == NULL) return head;
       fnt = head;
       rear = head->next;
       do
       {
	       if (fnt->val == rear->val)
	       {
		       deleteNode(fnt, rear);
	       }
	       else
	       {
	            fnt = rear;
	            if(rear)
	       		    rear = rear->next;
	            else
		            rear = NULL;
	       }
       }while(fnt != NULL && rear != NULL);
       return head;
    }
};
