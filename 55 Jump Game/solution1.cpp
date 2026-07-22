class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_idx = 0;

        if (nums[0] == 0 && nums.size() > 1)
            return false;

        for (int idx = 0; idx < nums.size() - 1; idx++) {
            if (nums[idx] + idx > max_idx && max_idx >= idx)
                max_idx = nums[idx] + idx;
        }

        return max_idx >= nums.size() - 1;
    }
};