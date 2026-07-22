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
void dfs(TreeNode* root, vector<vector<int>> &ans, int level) {
    if (!root)
        return;
    
    if (ans.size() <= level)
        ans.resize(level + 1);
    
    ans[level].push_back(root->val);

    dfs(root->left, ans, level + 1);
    dfs(root->right, ans, level + 1);
}

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        dfs(root, ans, 0);

        return ans; 
    }
};