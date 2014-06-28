class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *sortedList = new ListNode(-1), *currentNode = NULL;
        currentNode = sortedList;
        size_t len = lists.size();
        int minValue;
        ListNode** minNode = NULL;
        for(;;)
        {
            // init
            minValue = INT_MAX;
            minNode = NULL;
            
            // find node minest
            for (size_t i = 0;i < len;i ++)
            {
                if (lists[i] == NULL)
                    continue;
                else
                {
                    if ( lists[i]->val < minValue)
                    {
                        minValue = lists[i]->val;
                        minNode = &lists[i];
                    }
                }
            }
            
            if (minNode == NULL)
            {
                break;
            }
            ListNode* NewNode = new ListNode(minValue);
            currentNode->next = NewNode;
            currentNode = NewNode;
            *minNode = (*minNode)->next;
        }
        return sortedList->next;
    }
};
