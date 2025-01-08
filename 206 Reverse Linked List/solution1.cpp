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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev, *cur, *next;

        if (!head)
            return NULL;
        else if(!head->next)
            return head;

        prev = NULL;
        cur = head;
        next = head->next;

        while(cur) {
            cur->next = prev;
            if (!next)
                break;
            prev = cur;
            cur = next;
            next = next->next;
        }
        
        head = cur;

        return head;
    }
};
