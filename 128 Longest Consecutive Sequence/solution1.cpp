class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_length = 0;
        int cnt = 1;
        
        if (nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());

        for (int i=1; i<nums.size(); i++) {
            cout<<nums[i]<<" ";
            if (nums[i] - 1 == nums[i - 1]) {
                cnt++;
            } else if (nums[i] == nums[i - 1]) {
                
            } else {
                max_length = max(max_length, cnt);
                cnt = 1;
            }
        }

        return max(max_length, cnt);
    }
};