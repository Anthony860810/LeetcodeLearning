class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int days = prices.size();
        vector <int>buy(days, 0);
        vector <int>no_stock(days, 0);
        vector <int>freeze_day(days, 0);

        buy[0] = -prices[0];

        for (int day = 1; day < days; day++) {
            buy[day] = max(buy[day-1], no_stock[day-1] - prices[day]);
            freeze_day[day] = buy[day-1] + prices[day];
            no_stock[day] = max(no_stock[day-1], freeze_day[day-1]);
        }

        return max(no_stock[days-1], freeze_day[days-1]);
    }
};