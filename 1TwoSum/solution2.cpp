class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> Map;
        vector<int> ans;
        for(int idx=0; idx<nums.size(); idx++){
            int complement = target-nums[idx];
            if (Map.count(complement)==0){
                Map.insert(pair<int,int>(nums[idx],idx));
            }
            else{
                ans.push_back(Map[complement]);
                ans.push_back(idx);
            }
        }
        return ans;
    }
};
