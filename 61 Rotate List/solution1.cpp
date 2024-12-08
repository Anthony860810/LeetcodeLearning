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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *cur = head;
        ListNode *tail = NULL;
        int list_length = 1;
        
        if (!head)
            return NULL;
        else if (!head->next)
            return head;
        
        while (cur->next) {
            list_length++;
            cur = cur->next;
        }

        
        cur->next = head;
        cur = head;

        k = k % list_length;
        list_length = list_length - k;

        while(list_length > 1) {
            cur = cur->next;
            list_length--;
        }        

        head = cur->next;
        cur->next = NULL;

        return head;
    }
};