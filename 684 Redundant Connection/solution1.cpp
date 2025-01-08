class Solution {

private:
    int find(int node, vector<int> &parent)
    {
        if (parent[node] != node)
            return find(parent[node], parent);
        return node;
    }

    bool unionset(int node1, int node2, vector<int> &parent, vector<int> &rank)
    {
        int parent_of_node1 = find(node1, parent);
        int parent_of_node2 = find(node2, parent);

        if (parent_of_node1 == parent_of_node2)
            return false;

        if (rank[parent_of_node1] > rank[parent_of_node2])
            parent[parent_of_node2] = parent_of_node1;
        else if (rank[parent_of_node1] > rank[parent_of_node2])
            parent[parent_of_node1] = parent_of_node2;
        else {
            parent[parent_of_node2] = parent_of_node1;
            rank[parent_of_node1]++;
        }

        return true;
    }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int edge_size = edges.size();
        vector<int> parent(edge_size + 1);
        vector<int> rank(edge_size + 1, 0);

        for (int idx = 0; idx < edge_size; idx++)
            parent[idx] = idx;
        
        for (auto edge: edges) {
            if (!unionset(edge[0], edge[1], parent, rank)) {
                return edge;
            }
        }

        return {};
    }
};