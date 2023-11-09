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
    int CaculateLen(ListNode *head){
        int len=0;
        while(head->next!=NULL){
            head = head->next;
            len++;
        }
            return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL ||headB==NULL){
            return NULL;
        }
        ListNode *A = headA;
        ListNode *B = headB;
        int m = CaculateLen(A);
        int n = CaculateLen(B);
        A = headA;
        B = headB;
        if(m>n){
            for(int i=0; i<m-n ; i++){
                A = A->next;
            }
        }
        else{
            for(int i=0; i<n-m ; i++){
                B = B->next;
            }
        }
        while(A!=NULL)
        {
            if(A==B){
                return A;
            }
            A = A->next;
            B = B->next;
        }
        return NULL;
    }
};