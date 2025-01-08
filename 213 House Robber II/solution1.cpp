class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(), 0);
        vector<int> dp2(nums.size(), 0);
        int dp1_max;
        int dp2_max;

        if (nums.size() == 1)
            return nums[0];
        else if (nums.size() == 2)
            return max(nums[0], nums[1]);
        
        dp1[1] = nums[1];
        dp1[2] = max(nums[1], nums[2]);
        for (int idx = 3; idx < nums.size(); idx++)
            dp1[idx] = max(dp1[idx - 1], dp1[idx - 2] + nums[idx]);
        
        dp2[0] = nums[0];
        dp2[1] = max(nums[0], nums[1]);
        for (int idx = 2; idx < nums.size() - 1; idx++)
            dp2[idx] = max(dp2[idx - 1], dp2[idx - 2] + nums[idx]);

        dp1_max = max(dp1[nums.size()-1], dp1[nums.size()-2]);
        dp2_max = max(dp2[nums.size()-2], dp2[nums.size()-3]);

        return max(dp1_max, dp2_max);

    }
};