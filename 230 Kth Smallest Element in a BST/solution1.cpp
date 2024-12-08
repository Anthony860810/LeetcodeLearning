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

vector<int> ans;

void DFS(TreeNode* root) {
    if (root)
        ans.push_back(root->val);
    
    if (root->right)
        DFS(root->right);
    if (root->left)
        DFS(root->left);
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        ans = {};
        DFS(root);
        sort(ans.begin(), ans.end());

        for (int i=0; i<ans.size();i++)
            cout<< ans[i]<<" ";

        return ans[k-1];
    }
};