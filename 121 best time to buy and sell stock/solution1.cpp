class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> cur_day_max_profit(prices.size(), INT_MAX);
        int min_price = prices[0];
        cur_day_max_profit[0] = 0;

        for (int day = 1; day < prices.size(); day++) {
             min_price = min(prices[day], min_price);
             cur_day_max_profit[day] = max(cur_day_max_profit[day-1], prices[day] - min_price);
        }
        return cur_day_max_profit.back();
    }
};