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
        int size = 0;
        ListNode *cur = head;
        ListNode *prev;

        while (cur) {
            cur = cur->next;
            size++;
        }

        if (size - n == 0)
            return head->next;

        cur = head;

        n = size - n;
        
        while (n > 0) {
            prev= cur;
            cur = cur->next;
            n--;
        }

        prev->next = cur->next;

        return head;
    }
};
