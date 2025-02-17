class Solution {
    private:
        void dfs(const vector<int>& nums, int idx, vector<int> &subset, vector<vector<int>> &ans) {
            ans.push_back(subset);
    
            for (int i = idx; i < nums.size(); i++) {
                subset.push_back(nums[i]);
                dfs(nums, i+1, subset, ans);
                subset.pop_back();
            }
        }
    
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> subset;
            
            dfs(nums, 0, subset, ans);
    
            return ans;
        }
    };
    