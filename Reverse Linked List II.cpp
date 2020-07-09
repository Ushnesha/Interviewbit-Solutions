/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::reverseBetween(ListNode* A, int m, int n) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    
     ListNode* p=A, *q=new ListNode(-1), *cur;
     q->next=p;
    int count=1, flag=1;
    while(p&&p->next){
        if(count>=m&&count<n){
            if(count==m) flag=0;
            cur=p->next;
            ListNode* next = cur->next;
            cur->next=q->next;
            q->next=cur;
            p->next=next;
        }
        if(count>=n) break;
        if(flag){
            q=q->next;
            p=p->next;
        }
        count++;
    }
    return q->val == -1 ? q->next : A;
}
