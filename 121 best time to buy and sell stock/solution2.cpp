class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_day_max_profit = 0;
        int min_price = prices[0];

        for (int day = 1; day < prices.size(); day++) {
             min_price = min(prices[day], min_price);
             cur_day_max_profit = max(cur_day_max_profit, prices[day] - min_price);
        }
        return cur_day_max_profit;
    }
};