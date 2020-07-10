/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* reverseList(ListNode* node){
    ListNode* cur=node, *prev=NULL;
    while(cur){
        ListNode* next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    return prev;
}
ListNode* Solution::reorderList(ListNode* A) {
    if(!A || !A->next) return A;
    ListNode* p=A, *q=A, *r=NULL, *a, *b;
    while(q && q->next){
        p=p->next;
        q=q->next->next;
    }
    q=reverseList(p->next);
    p->next=NULL;
    p=A;
    while(p || q){
        if(p){
            if(!r) r=p;
            else {
                r->next=p;
                r=r->next;
            }
            p=p->next;
        }
        if(q){
            r->next=q;
            r=r->next;
            q=q->next;
        }
    }
    return A;
}
