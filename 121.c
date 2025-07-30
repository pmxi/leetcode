class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int current_price = 0;
            int min_price = prices[0];
            int max_profit = 0;
            int potential_profit = 0;
            // at least two days are necessary to make a trade
            if (prices.size() < 2) return 0;
            for (int day = 1; day < prices.size(); day++) {
                current_price = prices[day];
                if (current_price < min_price) {
                    min_price = current_price;
                }
                potential_profit = current_price - min_price;
                if (potential_profit > max_profit) {
                    max_profit = potential_profit;
                }
            }
            return max_profit;
        }
};
