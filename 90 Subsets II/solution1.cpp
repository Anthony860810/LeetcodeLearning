class Solution {
    private:
        void dfs(vector<int>& nums, vector<int> &subset, vector<vector<int>> &ans, int start) {
            unordered_set<int> nums_set;
            
            ans.push_back(subset);
    
            for (int idx = start; idx < nums.size(); idx++) {
                if (nums_set.find(nums[idx]) != nums_set.end())
                    continue;
                nums_set.insert(nums[idx]);
                subset.push_back(nums[idx]);
                dfs(nums, subset, ans, idx+1);
                subset.pop_back();
            }
        }
    
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>> ans;
            vector<int> subset;
    
            sort(nums.begin(), nums.end());
    
            dfs(nums, subset, ans, 0);
    
            return ans;
        }
    };
    