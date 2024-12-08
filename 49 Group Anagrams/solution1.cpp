class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans = {};
        unordered_map<string, vector<string>> category_dict;

        for (auto str: strs) {
            string word = str;
            sort(word.begin(), word.end());
            category_dict[word].push_back(str);
        }

        for(auto str_group: category_dict)
            ans.push_back(str_group.second);

        return ans;
    }
};