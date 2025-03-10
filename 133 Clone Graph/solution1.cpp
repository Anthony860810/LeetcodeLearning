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
private:
    Node* dfs(Node *node, unordered_map <Node*, Node*> &map) {
        if (!node)
            return NULL;

        if (map.find(node) != map.end())
            return map[node];
        
        Node *new_node = new Node(node->val);
        map[node] = new_node;

        for (auto neighbor: node->neighbors)
            new_node->neighbors.push_back(dfs(neighbor, map));
        
        return new_node;
    }


public:
    Node* cloneGraph(Node* node) {
        unordered_map <Node*, Node*> map;
        
        return dfs(node, map);
    }
};
