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
    private:
        void dfs(TreeNode* root, int &node_cnt, int cur_max_val) {
            if (!root)
                return;
    
            if (cur_max_val <= root->val) {
                cur_max_val = root->val;
                node_cnt++;
            }
    
            dfs(root->right, node_cnt, cur_max_val);
            dfs(root->left, node_cnt, cur_max_val);
        }
    
    public:
        int goodNodes(TreeNode* root) {
            int node_cnt = 0;
            int cur_max_val = -100001;
    
            dfs(root, node_cnt, cur_max_val);
    
            return node_cnt;
        }
    };