class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq;

        for(auto var: nums){
            freq[var]++;
            if(freq[var] > 1)
                return true;
        }
        return false;
    }
};