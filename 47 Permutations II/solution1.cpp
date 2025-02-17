class Solution {
    private:
        void dfs(vector<int>& nums, vector<vector<int>> &ans, int start) {
            if (start == nums.size()) {
                ans.push_back(nums);
                return;
            }
    
            unordered_set<int> nums_set;
    
            for (int idx = start; idx < nums.size(); idx++) {
                if (nums_set.find(nums[idx]) != nums_set.end())
                    continue;
                
                nums_set.insert(nums[idx]);
                swap(nums[start], nums[idx]);
                dfs(nums, ans, start+1);
                swap(nums[start], nums[idx]);
            }
        }
    
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<vector<int>> ans;
    
            sort(nums.begin(), nums.end());
    
            dfs(nums, ans, 0);
    
            return ans;
        }
    };