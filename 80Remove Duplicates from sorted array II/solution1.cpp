class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 2;
        
        if (nums.size() <= 2)
            return nums.size();

        for (int idx = 2; idx < nums.size(); idx++) {
            if (nums[idx] != nums[count-2]) {
                nums[count] = nums[idx];
                count++;
            }
        }
        return count;
    }
};