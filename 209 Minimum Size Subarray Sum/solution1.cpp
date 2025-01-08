class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_size = INT_MAX;
        int slow_ptr = 0;
        int sum = 0;

        for (int fast_ptr = 0; fast_ptr < nums.size(); fast_ptr++) {
            sum += nums[fast_ptr];

            while (sum >= target) {
                min_size = min(min_size, fast_ptr - slow_ptr +1);
                sum -= nums[slow_ptr];
                slow_ptr++;
            }
        }

        return (min_size == INT_MAX) ? 0 : min_size;
    }
};