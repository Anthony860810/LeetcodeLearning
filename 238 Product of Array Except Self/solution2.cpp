class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size());
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        int end = nums.size() - 1;

        left[0] = nums[0];
        right[end] = nums[end];

        for (int i = 1; i < nums.size(); i++) {
            left[i] = left[i - 1] * nums[i];
            right[end - i] = right[end - i + 1] * nums[end - i];
        }

        res[0] = right[1];
        res[end] = left[end - 1];

        for (int i = 1; i < end; i++) {
            res[i] = left[i - 1] * right[i + 1];
        }

        return res;
    }
};
