#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void pnt_list(struct ListNode* head)
{
    while (head!=NULL)
    {
        printf("%d->", head->val);
        head = head->next;
    }
    printf("\n");
}

int listLen(struct ListNode* head)
{
    int ans = 0;
    while (head!=NULL)
    {
        ans++;
        head = head->next;
    }
    return ans;
}

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head==NULL) return NULL;
    int len = listLen(head);
    k = k % len;
    if (k==0) return head;

    struct ListNode* p = (struct ListNode*)malloc(sizeof (struct ListNode));
    p->next = head;
    for (int i=0; i<len-k; i++)
    {
        p = p->next;
    }

    struct ListNode* newHead = (struct ListNode*)malloc(sizeof (struct ListNode));
    newHead = p->next;

    struct ListNode* tp= (struct ListNode*)malloc(sizeof (struct ListNode));
    for (tp=p; tp->next!=NULL; tp =  tp->next) ;
    p->next = NULL;
    tp->next = head;
    return newHead;
}


int main()
{
    printf("start\n");
    struct ListNode* head = (struct ListNode*)malloc(sizeof (struct ListNode));
    struct ListNode* second= (struct ListNode*)malloc(sizeof (struct ListNode));
    head->val = 1;
    second->val = 2;
    head->next = second;
    second->next = NULL;

    pnt_list(rotateRight(head, 1));
    return 0;
}
