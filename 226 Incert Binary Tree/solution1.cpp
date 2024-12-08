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

void InvertBinaryTree(TreeNode* root) {
    if (root == NULL)
        return;
    
    TreeNode *node_ptr = root->right;

    root->right = root->left;
    root->left = node_ptr;

    InvertBinaryTree(root->right);
    InvertBinaryTree(root->left);

}


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == NULL)
            return NULL;
        else if(root->left == NULL && root->right == NULL)
            return root;

        InvertBinaryTree(root);
        
        return root;
    }
};