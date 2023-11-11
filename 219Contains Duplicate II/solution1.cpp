class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        freq[nums[0]] = 0;

        for(int idx=1; idx< nums.size(); idx++){
                if(freq.count(nums[idx]))
                    if(abs(freq[nums[idx]]-idx) <= k)
                        return true;
                freq[nums[idx]] = idx;
                
        }
        return false;
    }
};