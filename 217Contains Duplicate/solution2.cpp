class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> set;

        for (auto num: nums) {
            if (set.find(num) == set.end())
                set.insert(num);
            else
                return true;
        }

        return false;
    }
};