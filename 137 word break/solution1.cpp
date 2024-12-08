class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size() + 1, false);
        dp[0] = true;

        for (int string_idx = 1; string_idx <= s.length(); string_idx++) {
            for (int dict_idx = 0 ; dict_idx < wordDict.size(); dict_idx++) {
                int start = string_idx - wordDict[dict_idx].length();
                if (start >= 0 && dp[start] && s.substr(start, wordDict[dict_idx].length()) == wordDict[dict_idx])
                    dp[string_idx] = true;
            }
        }

        return dp[s.size()];
    }
};