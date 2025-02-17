class Solution {
    private:
        void dfs(vector<int>& nums, int target, int idx, vector<int> &combination, vector<vector<int>> &ans) {
            if (target == 0) {
                ans.push_back(combination);
                return;
            } else if (target < 0 || idx == nums.size()) {
                return;
            }

            combination.push_back(nums[idx]);
            dfs(nums, target-nums[idx], idx+1, combination, ans);
            combination.pop_back();

            while (idx+1 < nums.size() &&nums[idx] == nums[idx+1]) {
                idx++;
            }

            dfs(nums, target, idx+1, combination, ans);
        }
    
    public:
        vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
            vector<vector<int>> ans;
            vector<int> combination;
    
            sort(nums.begin(), nums.end());
            dfs(nums, target, 0, combination, ans);
    
            return ans;
        }
    };
    