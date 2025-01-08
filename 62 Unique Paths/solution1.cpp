class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector <int>> dp(m, vector<int>(n, 0));
        
        for (int idx = 0; idx < n; idx++)
            dp[0][idx] = 1;
        
        for(int idx = 0; idx < m; idx++)
            dp[idx][0] = 1;

        for (int row = 1; row < m; row++) {
            for (int col = 1; col < n; col++)
                dp[row][col] = dp[row - 1][col] + dp[row][col - 1];
        }

        return dp[m - 1][n - 1];
    }
};