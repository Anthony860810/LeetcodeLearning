class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int ans = (nums.size()+1) * nums.size() / 2;
    
            for (auto num: nums)
                ans -= num;
    
            return ans;
        }
    };