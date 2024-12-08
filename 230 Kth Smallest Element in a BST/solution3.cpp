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

void inorderTraversal(TreeNode* root, int &k, int &ans) {
    if (!root)
        return;
    
    
    inorderTraversal(root->left, k, ans);
    k--;
    if (k == 0) {
        ans = root->val;
        return;
    }
    inorderTraversal(root->right, k, ans);
        
}

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

        int ans;
        inorderTraversal(root, k, ans);

        return ans;
    }
};