/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//merge sort linked list

ListNode* merge(ListNode* A, ListNode* B){
    if(!A) return B;
    if(!B) return A;
    
    ListNode* head = NULL;
    
    if(A->val <= B->val){
        head = A;
        head->next = merge(A->next, B);
    }
    else{
        head = B;
        head->next = merge(A, B->next);
    }
    return head;
} 

ListNode* Solution::sortList(ListNode* A) {
    
    if(!A || !A->next) return A;
    
    ListNode* start = A;
    ListNode* end = A->next;
    
    while(end && end->next){
        start = start->next;
        end = end->next->next;
    }
    
    end = start->next;
    start->next = NULL;
    
    return merge(sortList(A), sortList(end)); 

}
