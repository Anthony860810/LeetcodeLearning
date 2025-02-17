class Solution {
    private:
        void dfs(vector<int>& nums, int target, int idx, vector<int> &combination, vector<vector<int>> &ans) {
            if (target == 0) {
                ans.push_back(combination);
                return;
            } else if (target < 0 || idx >= nums.size()) {
                return;
            }
    
            combination.push_back(nums[idx]);
            dfs(nums, target-nums[idx], idx, combination, ans);
            combination.pop_back();
            dfs(nums, target, idx+1, combination, ans);
        }
    
    public:
        vector<vector<int>> combinationSum(vector<int>& nums, int target) {
            vector<vector<int>> ans;
            vector<int> combination;
    
            dfs(nums, target, 0, combination, ans);
    
            return ans;
        }
    };
    