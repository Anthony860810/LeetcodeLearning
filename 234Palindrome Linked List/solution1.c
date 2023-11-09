/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head){
    if(head==NULL || head->next==NULL)
        return true;
    struct ListNode *reverse, *previous=NULL, *ptr=head;
    while(ptr){
        reverse = (struct ListNode*) malloc(sizeof(struct ListNode));
        reverse->next = previous;
        reverse->val = ptr->val;
        previous = reverse;
        ptr = ptr->next;
    }
    ptr = head;
    while(ptr){
        if(reverse->val!=ptr->val)
            return false;
        ptr = ptr->next;
        reverse = reverse->next;
    }
    return true;
}