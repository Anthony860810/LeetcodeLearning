/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        unordered_map <Node*, Node*> map;
        queue<Node*> q;
        
        map[node] = new Node(node->val);
        q.push(node);

        while (!q.empty()) {
            Node *cur = q.front();
            q.pop();

            for (auto neighbor: cur->neighbors) {
                if (map.find(neighbor) == map.end()) {
                    map[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }

                map[cur]->neighbors.push_back(map[neighbor]);
            }
        }

        return map[node];
    }
};
