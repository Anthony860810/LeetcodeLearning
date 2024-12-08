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
    int pairSum(ListNode* head) {
        vector<int> buffer;
        int max = 0;
        int length = 0;

        while (head) {
            buffer.push_back(head->val);
            head = head->next;
        }

        length = buffer.size();
        cout<<length<<endl;
        if (length == 2)
            return buffer[0] + buffer[1];

        for (int i = 0; i < length/2; i++) {
            if (buffer[i] + buffer[length - i - 1] > max)
                max = buffer[i] + buffer[length - i - 1];
        }

        return max;
    }
};