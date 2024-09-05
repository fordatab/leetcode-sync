class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int n = sequence.size();
        int m = word.size();
        vector<int> dp(n + 1, 0);
        
        // Iterate over the sequence, starting from the word's length
        for (int i = m; i <= n; i++) {
            // Check if the substring of length m starting from index i is equal to the word
            if (sequence.substr(i - m, m) == word) {
                dp[i] = dp[i - m] + 1;
            }
        }
        
        // Return the maximum dp value, which represents the maximum number of times the word can be repeated
        return *max_element(dp.begin(), dp.end());
    }
};
