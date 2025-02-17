/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;
        Node *cur = head;
        Node *new_head, *new_cur = NULL;

        if(!head)
            return NULL;

        new_head = new Node(cur->val);
        new_cur = new_head;
        map[cur] = new_cur;
        cur = cur->next;

        while(cur) {
            new_cur->next = new Node(cur->val);
            new_cur = new_cur->next;
            map[cur] = new_cur;
            cur = cur->next;
        }

        cur = head;
        new_cur = new_head;

        while(cur) {
            new_cur->random = map[cur->random];
            new_cur = new_cur->next;
            cur = cur->next;
        }

        return new_head;
    }
};
