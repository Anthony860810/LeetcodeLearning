class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(0, 0, nums, target);
    }

    int backtrack(int idx, int sum, vector<int>& nums, int target) {
        if (idx == nums.size())
            return sum == target;
        return backtrack(idx + 1, sum + nums[idx], nums, target) +
               backtrack(idx + 1, sum - nums[idx], nums, target);
    }
};