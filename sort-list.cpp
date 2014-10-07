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
    ListNode *sortList(ListNode *head) {
        if (head == NULL) return head;
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
        int curr = 0;
        while ( head != NULL && curr < k)
        {
            curr++;
            head = head->next;
        }
        return head;
    }
    
    ListNode *MergeList(ListNode *list1, int len1, ListNode *list2, int len2)
    {
        return NULL;
    }
    
    ListNode *MergeSort(ListNode *head, int n) {
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
