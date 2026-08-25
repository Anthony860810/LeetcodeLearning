class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            if (i > 0 && nums[i] == nums[i-1])
                continue;

            while (j < k) {
                int three_sum = nums[i] + nums[j] + nums[k];

                if (three_sum == 0) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    while (j < k && nums[j] == nums[j-1]) {
                        j++;
                    }
                } else if (three_sum < 0) {
                    j++;
                } else {
                    k--;
                }
            }

        }
        return res;
    }
};
