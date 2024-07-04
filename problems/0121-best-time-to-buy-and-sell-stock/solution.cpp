class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
        int r = 1;
        int price = 0;
        while (r < prices.size()) {
            price = max(prices[r] - prices[l], price); 
            if (prices[l] > prices[r]) {
                l = r++;
            } else {
                r++;
            }
        }
        return price;
    }
};
