class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> sell(prices.size(), 0);
        vector<int> buy = sell;
        buy[0] = -prices[0];
        for(int i=1; i<prices.size() ; i++){
            sell[i] = max(sell[i-1], buy[i-1]+prices[i]-fee);
            buy[i]  = max(buy[i-1], sell[i-1]-prices[i]);
        }
        return sell.back();
    }
};