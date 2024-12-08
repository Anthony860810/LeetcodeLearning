class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> robber_record(size, 0);

        if (nums.size() == 1)
            return nums[0];

        robber_record[0] = nums[0];
        robber_record[1] = max(robber_record[0], nums[1]);

        for (int idx = 2; idx < nums.size(); idx++) {
            robber_record[idx] = max(robber_record[idx - 2] + nums[idx], robber_record[idx - 1]);
        }

        return robber_record[nums.size() - 1];
    }
};