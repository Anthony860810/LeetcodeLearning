class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> tmp;
        tmp.reserve(nums.size());
        for (int idx = 0; idx < nums.size(); idx++) {
            tmp[ (idx+k) % nums.size()] = nums[idx];
        }
        for (int idx = 0; idx < nums.size(); idx++) {
            nums[idx] = tmp[idx];
        }
    }
};