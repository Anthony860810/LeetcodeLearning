class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hash_table;

        for (auto num: nums) {
            if (!hash_table.insert(num).second)
                return true;
        }

        return false;
    }
};
