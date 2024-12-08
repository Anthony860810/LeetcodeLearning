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

bool CompareLeftAndRight(TreeNode* left, TreeNode* right) {
    if (left && right) {
        if (left->val == right->val) {
            return CompareLeftAndRight(left->left, right->right) && CompareLeftAndRight(left->right, right->left);
        } else {
            return false;
        }
    } else if (left==NULL && right==NULL)
        return true;
      else
        return false;
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root->left && !root->right)
            return true;
        else if (!root->left || !root->right)
            return false;

        return CompareLeftAndRight(root->left, root->right);
    }
};