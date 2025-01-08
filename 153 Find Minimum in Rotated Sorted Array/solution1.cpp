class Solution {
public:
    int findMin(vector<int> &nums) {
        int min = nums[0];

        for (auto num: nums) {
            if (num < min)
                min = num;
        }

        return min;
    }
};
