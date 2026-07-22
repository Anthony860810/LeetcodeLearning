class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> category_dict;
        vector<vector<string>> ans;

        for (auto str: strs) {
            int count[26] = {};

            for (auto ch: str) {
                count[ch - 'a']++;
            }

            string key;
            for (int i = 0; i < 26; i++) {
                key += "#";
                key += to_string(count[i]);
            }

            category_dict[key].push_back(str);
        }

        for (auto str_group: category_dict)
            ans.push_back(str_group.second);

        return ans;
    }
};
