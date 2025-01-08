class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(), 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int idx = 2; idx < cost.size(); idx++)
            dp[idx] = min(dp[idx - 1], dp[idx - 2]) + cost[idx];
        
        return min(dp[cost.size() - 1], dp[cost.size() - 2]);
    }
};