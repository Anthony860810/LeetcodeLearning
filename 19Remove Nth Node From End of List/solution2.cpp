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
        int length = 0;
        ListNode *cur = head;
        
        while (cur) {
            cur = cur->next;
            length++;
        }

        if (length == 1)
            return NULL;

        length -= n;
        cur = head;

        if (length == 0) {
            return head->next;
        }

        while (length > 1) {
            cur = cur->next;
            length--;
        }

        if (n == 1)
            cur->next = NULL;
        else
            cur->next = cur->next->next;

        return head;

    }
};