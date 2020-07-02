/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    ListNode* tortoise=A;
        ListNode* hare=A;
        do{
            tortoise=tortoise->next;
            hare=hare->next->next;
        }while(tortoise!=hare && (hare && hare->next));
        if(!hare || !hare->next) return NULL;
        tortoise=A;
        while(tortoise!=hare){
            tortoise=tortoise->next;
            hare=hare->next;
        }
        return hare;
}
