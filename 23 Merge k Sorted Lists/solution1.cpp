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

 bool compare(const ListNode *a, const ListNode *b) {
    return a->val > b->val;
}

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return NULL;
        
        
        priority_queue<ListNode*, vector<ListNode*>, bool(*)(const ListNode*, const ListNode*)> minheap(compare);

        for (auto list: lists) {
            if (list)
                minheap.push(list);
        }
            
        ListNode *head = new ListNode(0);
        ListNode *cur = head;

        while (!minheap.empty()) {
            ListNode *node = minheap.top();
            
            minheap.pop();
            cur->next = node;
            cur = cur->next;
            node = node->next;
            
            if (node)
                minheap.push(node);
        }

        return head->next;
    }
};
