class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector <int> dp(amount+1, amount+1);
        dp[0] = 0;

        for (int dp_idx = 1; dp_idx < dp.size(); dp_idx++) {
            for (int coin_idx=0; coin_idx<coins.size(); coin_idx++) {
                if (dp_idx - coins[coin_idx] >= 0)
                    dp[dp_idx] = min(dp[dp_idx], dp[dp_idx - coins[coin_idx]]+1);
            }
        }

        return dp[amount] != amount+1 ? dp[amount] : -1;

    }
};