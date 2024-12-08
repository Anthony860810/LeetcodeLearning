class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        for(int i = 0; i < strs[0].size(); i++) {
            ans.push_back(strs[0][i]);
            for(int idx = 1; idx < strs.size(); idx++) {
                if (strs[idx][i] != ans.back()) {
                    ans.pop_back();
                    return ans;
                }
            }
        }

        return ans;
    }
};