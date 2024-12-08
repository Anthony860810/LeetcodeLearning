class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> output;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            if (i > 0 && nums[i] == nums[i-1])
                continue;

            while (j < k) {
                int threesum = nums[i] + nums[j] + nums[k];

                if (threesum == 0) {
                    output.push_back({nums[i], nums[j], nums[k]});
                    j++;

                    while (nums[j] == nums[j-1] && j < k) {
                        j++;
                    }
                }
                else if (threesum < 0)
                    j++;
                else
                    k--;
            }

        }
        return output;
    }
};