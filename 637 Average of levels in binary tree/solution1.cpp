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

vector <double> each_level_sum;
vector <int> each_level_node_cnt;

void DFS_calculate(TreeNode *root, int depth) {

    if (!root)
        return;
    
    if (each_level_node_cnt.size() < depth+1) {
        each_level_node_cnt.push_back(1);
        each_level_sum.push_back(root->val);
    } else {
        each_level_node_cnt[depth] += 1;
        each_level_sum[depth] += root->val;
    }

    depth = depth + 1;

    DFS_calculate(root->left, depth);
    DFS_calculate(root->right, depth);
}

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        each_level_sum = {};
        each_level_node_cnt = {};


        DFS_calculate(root, 0);

        for (int depth=0; depth < each_level_sum.size(); depth++)
            each_level_sum[depth] = each_level_sum[depth] / each_level_node_cnt[depth];

        return each_level_sum;
    }
};