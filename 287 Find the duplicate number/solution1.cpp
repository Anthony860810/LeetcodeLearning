class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> dict;

        for (auto num: nums) {
            if (dict.find(num) != dict.end())
                return num;
            dict.insert(num);
        }

        return -1;
    }
};