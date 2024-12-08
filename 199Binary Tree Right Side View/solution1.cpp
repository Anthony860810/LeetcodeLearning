/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */


void DFS(TreeNode* node, vector<int> *result, int depth)
{
    if (!node)
        return;
    if (result->size() < depth)
        result->push_back(node->val);
    else
        (*result)[depth-1] = node->val;
    
    DFS(node->left, result, depth+1);
    DFS(node->right, result, depth+1);

}


class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result = {};
        int depth = 1;

        DFS(root, &result, depth);
        
        return result;
    }
};