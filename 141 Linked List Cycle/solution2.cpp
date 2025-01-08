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
    bool hasCycle(ListNode* head) {
        ListNode *cur = head;

        if (!head)
            return false;
        else if (!head->next)
            return false;

        while (cur) {
            if (cur->val == 100001)
                return true;
            cur->val = 100001;
            cur = cur->next;
        }

        return false;
    }
};
