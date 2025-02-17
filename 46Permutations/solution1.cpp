class Solution {
    private:
        void dfs(vector<int>& nums, vector<vector<int>> &ans, int start) {
            if (start == nums.size()) {
                ans.push_back(nums);
                return;
            }
            
            for (int idx = start; idx < nums.size(); idx++) {
                swap(nums[start], nums[idx]);
                dfs(nums, ans, start+1);
                swap(nums[start], nums[idx]);
            }
        }
    
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>> ans;
    
            dfs(nums, ans, 0);
    
            return ans;
        }
    };
    