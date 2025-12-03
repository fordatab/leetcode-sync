class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // dp[c][val] = maximum length of a good subsequence
        //              with at most c changes and ending in value "val"
        vector<unordered_map<int, int>> dp(k + 1);

        // maxLen[c] = maximum length of a good subsequence
        //             with at most c changes (ending with any value)
        vector<int> maxLen(k + 1, 0);

        for (int num : nums) {
            // Go from k down to 0 so we don't reuse this element multiple times
            for (int c = k; c >= 0; --c) {
                // Case A: extend a subsequence that already ends with `num`
                int &cur = dp[c][num];
                cur += 1;  // either start new [num] or extend existing tail with same value

                // Case B: extend best subsequence with c-1 changes and some other ending
                if (c > 0) {
                    cur = max(cur, maxLen[c - 1] + 1);
                }

                // Update global best for this c
                maxLen[c] = max(maxLen[c], cur);
            }
        }

        return maxLen[k];
    }
};
