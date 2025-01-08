class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int text1_size = text1.size();
        int text2_size = text2.size();
        
        vector<vector <int>> dp(text1_size + 1, vector<int>(text2_size + 1, 0));

        for (int text1_idx = 1; text1_idx <= text1_size; text1_idx++) {
            for (int text2_idx = 1; text2_idx <= text2_size; text2_idx++) {
                const char text1_ch = text1[text1_idx - 1];
                const char text2_ch = text2[text2_idx - 1];

                if (text1_ch == text2_ch)
                    dp[text1_idx][text2_idx] = dp[text1_idx - 1][text2_idx - 1] + 1;
                else
                    dp[text1_idx][text2_idx] = max(dp[text1_idx - 1][text2_idx], dp[text1_idx][text2_idx - 1]);
            }
        }

        return dp[text1_size][text2_size];
    }
};