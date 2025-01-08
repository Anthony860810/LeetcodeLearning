class Solution {
public:
    int change(int amount, vector<int>& coins) {
        // int dp[amount + 1];
        
        vector<uint64_t> dp(amount + 1, 0);
        dp[0] = 1;

        for (auto coin_val: coins) {
            for (int target = coin_val; target <= amount; target++) {
                if (target - coin_val >= 0) {
                    dp[target] += dp[target - coin_val];
                }
            }
        }

        return dp[amount];
    }
};