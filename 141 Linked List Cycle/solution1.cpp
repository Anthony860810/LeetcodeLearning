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
        ListNode *slow, *fast;

        if (!head)
            return false;
        else if (!head->next)
            return false;

        slow = head;
        fast = head->next;

        while (slow && fast) {
            
            if (slow == fast)
                return true;
            if (!fast->next || !fast->next->next)
                break;

            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};
