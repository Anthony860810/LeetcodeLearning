/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int max(int a, int b){
    return  a>b ? a:b;
}

int DFS(struct TreeNode* node){
    if(node==NULL){
        return 0;
    }
    return 1 + max(DFS(node->left), DFS(node->right));
        
}

int maxDepth(struct TreeNode* root){
    if(root==NULL)
        return 0;
    return DFS(root);
}
