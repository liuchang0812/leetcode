/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    map<RandomListNode*, RandomListNode*> mapping; 
    RandomListNode *copyRandomList(RandomListNode *head) {

        RandomListNode *ans = new RandomListNode(-1);
        RandomListNode *cur = ans;
   
        RandomListNode *head_ = head;
        while (head_) {
            cur->next = new RandomListNode(head_->label);
            mapping[head_] =  cur->next;
            head_ = head_->next;
            cur = cur->next;
        }

        cur = ans->next;
        head_ = head;
        while (head_) {
            if (head_->random)
                cur->random = mapping[head_->random];
            head_ = head_->next;
            cur = cur->next;
        }
        return ans->next;
    }
};
