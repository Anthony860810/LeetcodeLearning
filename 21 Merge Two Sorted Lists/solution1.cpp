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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list1_cur, *list2_cur, *cur_node;

        if (!list1)
            return list2;
        else if (!list2)
            return list1;
        
        list1_cur = list1;
        list2_cur = list2;
        
        if (list1_cur->val <= list2_cur->val){
            cur_node = list1_cur;
            list1_cur = list1_cur->next;
        } else {
            cur_node = list2_cur;
            list2_cur = list2_cur->next;
        }

        while(list1_cur && list2_cur) {
            if (list1_cur->val <= list2_cur->val){
                cur_node->next = list1_cur;
                list1_cur = list1_cur->next;
            } else {
                cur_node->next = list2_cur;
                list2_cur = list2_cur->next;
            }
            cur_node = cur_node->next;
        }

        if (list1_cur)
            cur_node->next = list1_cur;
        if (list2_cur)
            cur_node->next = list2_cur;

        return list1->val <= list2->val ? list1 : list2;
    }
};
