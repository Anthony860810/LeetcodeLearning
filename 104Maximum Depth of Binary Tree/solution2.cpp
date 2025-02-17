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

class Solution {
    int dfs(TreeNode* node, int depth) {
        if (!node)
            return depth;
        depth++;
        return max(dfs(node->left, depth), dfs(node->right, depth));
    }

public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        return dfs(root, depth);
    }
};
