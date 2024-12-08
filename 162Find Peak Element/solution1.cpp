int findpeak(vector<int>& nums, int left, int right)
{
    if (left == right) {
        // Base case: only one element in this range
        return left;
    }
    
    int mid = left + (right - left) / 2;

    // Compare mid with its next element to decide the direction
    if (nums[mid] > nums[mid + 1]) {
        // Look in the left half
        return findpeak(nums, left, mid);
    } else {
        // Look in the right half
        return findpeak(nums, mid + 1, right);
    }

}

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        if (nums.size() == 1 || (nums.size() == 2 && nums[1] < nums[0]))
            return 0;

        return findpeak(nums, 0, nums.size() - 1);

    }
};