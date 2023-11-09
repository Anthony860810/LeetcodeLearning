/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool DFS(struct TreeNode* root, struct TreeNode* max, struct TreeNode* min){
    if(!root)
        return true;
    if(min && root->val <= min->val){
       return false;  
    }
    if(max && root->val >= max->val){
        return false;
    }
    return DFS(root->left, root, min) && DFS(root->right, max, root);
}

bool isValidBST(struct TreeNode* root){
    return DFS(root, NULL, NULL);
}

