class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        int n = coins.size();
        
        // 1-based prefix sum array to avoid out-of-bounds checks
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            long long bags = coins[i][1] - coins[i][0] + 1;
            prefix[i + 1] = prefix[i] + bags * coins[i][2];
        }
        
        long long max_coins = 0;
        
        // 1. Align Right: Window ends at coins[i][1]
        int left = 0;
        for (int i = 0; i < n; i++) {
            int window_start = coins[i][1] - k + 1;
            
            // Find the first interval that overlaps with the window
            while (coins[left][1] < window_start) {
                left++;
            }
            
            // Sum of fully covered intervals (from left + 1 to i)
            long long fully_covered = prefix[i + 1] - prefix[left + 1];
            
            // Add the partially covered interval on the left edge
            long long overlap_len = coins[left][1] - max(coins[left][0], window_start) + 1;
            long long total = fully_covered + overlap_len * coins[left][2];
            
            max_coins = max(max_coins, total);
        }
        
        // 2. Align Left: Window starts at coins[i][0]
        int right = 0;
        for (int i = 0; i < n; i++) {
            int window_end = coins[i][0] + k - 1;
            
            // Find the first interval that falls completely outside the right edge
            while (right < n && coins[right][0] <= window_end) {
                right++;
            }
            
            int last = right - 1; // The interval overlapping the right edge
            
            // Sum of fully covered intervals (from i to last - 1)
            long long fully_covered = prefix[last] - prefix[i];
            
            // Add the partially covered interval on the right edge
            long long overlap_len = min(coins[last][1], window_end) - coins[last][0] + 1;
            long long total = fully_covered + overlap_len * coins[last][2];
            
            max_coins = max(max_coins, total);
        }
        
        return max_coins;
    }
};