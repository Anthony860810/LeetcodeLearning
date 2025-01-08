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
    void reorderList(ListNode* head) {
        vector <ListNode*> buffer;
        ListNode* cur = head;
        int length;

        if (!head)
            return;
        else if (!head->next)
            return;

        while (cur) {
            buffer.push_back(cur);
            cur = cur->next;
        }

        length = buffer.size();

        for (int idx = 0; idx <= length - 1; idx++) {
            if (idx == length / 2)
                buffer[idx]->next = NULL;
            else if (idx < length / 2)
                buffer[idx]->next = buffer[length - idx - 1];
            else
                buffer[idx]->next = buffer[length - idx];

                
        }
    }
};
