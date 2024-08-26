class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> hold(n+1);
        vector<int> buy(n+1);
        hold[n] = prices[n-1]-fee;
        buy[n] = 0;
        for (int x = n-1; x > -1; x--) {
            hold[x] = max(hold[x+1], prices[x] - fee + buy[x+1]);
            buy[x] = max(buy[x+1], -prices[x] + hold[x+1]);

        }
        for (auto a : hold) {
            cout << a << " ";
        }
        cout << endl;
        for (auto b : buy) {
            cout << b << " ";
        }
        return buy[0];
    }
};