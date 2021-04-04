/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* oddEvenList(struct ListNode* head){
    if (head==NULL || head->next==NULL || head->next->next==NULL)
        return head;
    struct ListNode *odd= (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *even= (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode *cur = head->next->next;
    odd->val = head->val;
    even->val = head->next->val;
    even->next = NULL;
    struct ListNode *pre_odd = odd, *pre_even = even;
    int count=1;
    
    while(cur){
        if(count%2==1){
            struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
            node->val = cur->val;
            node->next = NULL;
            pre_odd->next = node;
            pre_odd = node;
            
        }
        else{
            struct ListNode* node = (struct ListNode*) malloc(sizeof(struct ListNode));
            node->val = cur->val;
            node->next = NULL;
            pre_even->next = node;
            pre_even = node;
        }
        count++;
        cur = cur->next;
    }
    pre_odd->next = even;
    return odd;
}