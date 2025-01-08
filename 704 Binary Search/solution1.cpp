class Solution {

private:
    int binarysearch(int left, int right, vector<int>& nums, int target) {
        if (left > right)
            return -1;
        
        int center = (left + right) / 2;
        
        if (nums[center] == target)
            return center;
        else if (nums[center] > target)
            return binarysearch(left, center - 1, nums, target);
        else
            return binarysearch(center + 1, right, nums, target);
    }

public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;
        
        return binarysearch(0, nums.size(), nums, target);
    }
};
