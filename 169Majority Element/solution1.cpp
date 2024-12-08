class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;
        int result = nums[0];
        for (int idx=1; idx < nums.size(); idx++) {
            if (nums[idx] == result)
                count++;
            else
                count--;
            if (count < 0) {
                result = nums[idx];
                count = 1;
            }
        }
        return result;
    }
};