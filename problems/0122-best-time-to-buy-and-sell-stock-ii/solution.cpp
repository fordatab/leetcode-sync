class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy_1 = 0;
        int hold_1 = prices.back();
        int buy_0 = 0;
        int hold_0 = 0;
        for (int x = prices.size()-2; x > -1; x--) {
            buy_0 = max(buy_1, -prices[x] + hold_1);
            hold_0 = max(hold_1, prices[x] + buy_1);

            buy_1 = buy_0;
            hold_1 = hold_0;
        }
        return buy_0;
    }
};
