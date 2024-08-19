class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector<int> out(prices.size());
        stack<pair<int,int>> stk;
        for (int x = 0; x < prices.size(); x++) {
            while (!stk.empty() && stk.top().first >= prices[x]) {
                out[stk.top().second] = stk.top().first-prices[x];
                stk.pop();
            }
            stk.push({prices[x], x});
        }
        while (!stk.empty()) {
            out[stk.top().second] = stk.top().first;
            stk.pop();
        }
        return out;
    }
};