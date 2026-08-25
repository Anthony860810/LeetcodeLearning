class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());

        res[1] = nums[0];

        for (int i = 2; i < nums.size(); i++) {
            res[i] = res[i - 1] * nums[i - 1];
        }

        int right = nums[nums.size() - 1];
        res[0] = 1;

        for (int i = nums.size() - 2; i >= 0; i--) {
            res[i] *= right;
            right *= nums[i];
        }

        return res;
    }
};
