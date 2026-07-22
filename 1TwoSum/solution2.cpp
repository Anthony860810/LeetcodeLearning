class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;

        for (int i=0; i<nums.size(); i++) {
            if (!hash_table.count(target - nums[i])) {
                hash_table.insert(make_pair(nums[i], i));
            } else {
                return {hash_table[target - nums[i]],i};
            }

        }

        return {};
    }
};
