class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> count;
        int min_fruit = INT_MAX;
        
        // Count all fruits and find minimum
        for (int x : basket1) {
            count[x]++;
            min_fruit = min(min_fruit, x);
        }
        for (int x : basket2) {
            count[x]--;
            min_fruit = min(min_fruit, x);
        }
        
        // Check if rearrangement is possible
        vector<int> swaps;
        for (auto& [fruit, diff] : count) {
            if (diff % 2 != 0) return -1;
            // Add surplus fruits from basket1 (positive diff)
            for (int i = 0; i < abs(diff) / 2; i++) {
                swaps.push_back(fruit);
            }
        }
        
        // Sort swaps to pair expensive with expensive
        sort(swaps.begin(), swaps.end());
        
        long long cost = 0;
        // Only need first half of swaps (each swap involves 2 fruits)
        for (int i = 0; i < swaps.size() / 2; i++) {
            cost += min(swaps[i], 2 * min_fruit);
        }
        
        return cost;
    }
};