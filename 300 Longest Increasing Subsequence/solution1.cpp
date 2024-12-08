class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int max_length = 0;

        if (nums.size() == 1)
            return 1;

        for (int idx = 1; idx < nums.size(); idx++) {
            for (int num = 0; num < idx; num++) {
                if (nums[idx] > nums[num]) {
                    dp[idx] = max(dp[num] + 1, dp[idx]);
                }
            }
            max_length = max(max_length, dp[idx]);
        }

        return max_length;
    }
};