class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        for (int i = 0; i < strs[0].size(); i++) {
            for (int idx = 1; idx < strs.size(); idx++) {
                if (strs[idx][i] != strs[0][i]) {
                    return strs[0].substr (0,i);
                }
            }
        }

        return strs[0];
    }
};