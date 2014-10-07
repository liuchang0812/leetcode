
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        return MergeSort(head, Length(head));
    }
private:
    int Length(ListNode *head)
    {
        int ans=0;
        while (head != NULL)
        {
            ans++;
            head = head->next;
        }
        return ans;
    }
    
    ListNode *KthNode(ListNode* head, int k)
    {
        int curr = 1;
        while ( head != NULL && curr < k)
        {
            curr++;
            head = head->next;
        }
        return head;
    }
    
    ListNode *MergeList(ListNode *list1, int len1, ListNode *list2, int len2)
    {

        ListNode *head, *curr;
        head = new ListNode(1);
        curr = head;

        int i=0, j=0;
        while (i < len1 && j < len2)
        {
            if (list1->val < list2->val)
            {
                ListNode* tmp = new ListNode(list1->val);
                curr->next = tmp;
                curr = tmp;
                list1=list1->next; i++;
            }
            else
            {
                ListNode* tmp = new ListNode(list2->val);
                curr->next = tmp;
                curr = tmp;
                list2=list2->next;j++;
            }
        }
        //return list1;
        while (i < len1)
        {
                ListNode* tmp = new ListNode(list1->val);
                curr->next = tmp;
                curr = tmp;
                list1=list1->next; i++;
        }
        while(j < len2)
        {
            
                ListNode* tmp = new ListNode(list2->val);
                curr->next = tmp;
                curr = tmp;
                list2=list2->next;j++;
        }
        return head->next;
    }
    
    ListNode *MergeSort(ListNode *head, int n) {
        if (n==0) return NULL;
        if (n==1) return head;
        else
        {
         ListNode *left, *right;
         left = MergeSort(head, n/2);
         right = MergeSort(KthNode(head, n/2+1), n-n/2);
         return MergeList(left, n/2, right, n-n/2);
        }
    }
};
