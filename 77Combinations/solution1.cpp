class Solution {
    private:
        void dfs(int nums, int cnt, int start, vector<int> &combination, vector<vector<int>> &ans) {
            if (combination.size() == cnt) {
                ans.push_back(combination);
                return;
            }
    
            for (int num = start; num <= nums; num++) {
                combination.push_back(num);
                dfs(nums, cnt, num+1, combination, ans);
                combination.pop_back();
            }
            
        }
    
    public:
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> ans;
            vector<int> combination;
            
            dfs(n, k, 1, combination, ans);
    
            return ans;
        }
    };