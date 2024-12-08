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

int sum;

int Sum_Tree(TreeNode* root, int total) {
    if (!root) {
        return 0;
    } else if(!root->right && !root->left) {
        return (total*10 + root->val);
    } else
        return Sum_Tree(root->left, total*10 + root->val) + Sum_Tree(root->right, total*10 + root->val);
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
 
        if (root->right == NULL && root->left == NULL)
            return root->val;

        return Sum_Tree(root, 0);
    }
};