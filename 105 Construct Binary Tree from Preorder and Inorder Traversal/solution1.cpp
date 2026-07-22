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
    unordered_map<int, int> inorder_map;
    int preorder_idx = 0;
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int start, int end){
        if (start > end)
            return nullptr;
        
        int val = preorder[preorder_idx];
        ++preorder_idx;
        TreeNode* root = new TreeNode(val);

        int inorder_root_idx = inorder_map[val];

        root->left = build(preorder, inorder, start, inorder_root_idx-1);
        root->right = build(preorder, inorder, inorder_root_idx+1, end);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i < inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }
        
        return build(preorder, inorder, 0, inorder.size()-1);
    }
};