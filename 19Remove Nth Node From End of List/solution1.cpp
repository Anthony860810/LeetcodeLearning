/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur=head;
        ListNode *past=cur;
        int len=0;
        while (cur!=NULL){
            len++;
            cur = cur->next;
        }
        if(len==n){
            return head->next;
        }
        int target = len-n;
        cur = head;
        while(target!=0){
            past=cur;
            cur=cur->next;
            target--;
        }
        past->next = cur->next;
        return head;
    }
};