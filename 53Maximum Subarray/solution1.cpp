class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int tmp=nums[0];
        
        for(int i=1; i<nums.size();i++){
            tmp = nums[i] > (tmp+nums[i]) ? nums[i] : (tmp+nums[i]);
            ans = tmp > ans ? tmp : ans;
        }
        return ans;
    }
};