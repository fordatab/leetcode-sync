class Solution {
public:
    struct preRange {
        int left;
        int right;
        long long prefixSum;
    };

    long long maximumCoins(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());
        long long out = 0;
        long long prefix = 0;
        vector<preRange> pre;
        for (auto& range : coins) {
            prefix += range[2] * (long long)(range[1] - range[0] + 1);
            pre.push_back({range[0], range[1], prefix});
        }
        // (1, 5, 4), (10, 12, 3)
        // (1, 5, 20), (10, 12, 29) 

        // sliding window
        // indices to a range within pre;
        int left = 0;
        for (int i = 0; i < pre.size(); i++) {
            int l = pre[i].left;
            int r = pre[i].right;
            long long prefixSum = pre[i].prefixSum; 
            while (pre[left].right < r - (k-1)) {
                left++;
            }
            long long total = prefixSum - pre[left].prefixSum; // Fully covered intervals (left+1 to i)
            long long overlap_len = pre[left].right - max(pre[left].left, r - k + 1) + 1;
            long long overlap_coins = overlap_len * coins[left][2];
            total += overlap_coins;
            out = max(out, total);
        }

        int right = 0; // Notice right starts at 0, not pre.size() - 1, because we move it forward
        for (int i = 0; i < pre.size(); i++) { // We can just iterate i forward
            int l = pre[i].left;
            
            // Move right pointer until the interval's left edge is outside the window
            while (right < pre.size() && pre[right].left <= l + (k - 1)) {
                right++;
            }
            
            // The interval that might be partially covered is right - 1
            int last_included = right - 1;
            
            // Calculate fully covered intervals (from i to last_included - 1)
            long long fully_covered = 0;
            if (last_included > i) {
                fully_covered = pre[last_included - 1].prefixSum - (i == 0 ? 0 : pre[i - 1].prefixSum);
            }
            
            // Calculate overlap length for the partially covered interval
            long long overlap_len = min((long long)pre[last_included].right, (long long)l + k - 1) - pre[last_included].left + 1;
            long long overlap_coins = overlap_len * coins[last_included][2];
            
            long long total = fully_covered + overlap_coins;
            out = max(out, total);
        }
        return out;
    }
};