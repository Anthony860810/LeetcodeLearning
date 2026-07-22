class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            vector<int> dp(amount+1,amount+1);
    
            dp[0] = 0;
    
            for(int val = 1; val <= amount; val++) {
                for (auto coin_val: coins) {
                    if (coin_val <= val)
                        dp[val] = min(dp[val], dp[val-coin_val] + 1);
                }
            }
    
            return dp[amount] > amount ? -1 : dp[amount];
        }
    };
    