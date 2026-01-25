class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> palindrome(n, vector<bool> (n));
        vector<int> dp(n);
        for (int end = 0; end < n; end++) {
            int minimumCut = end;
            for (int start = 0; start <= end; start++) {
                if (s[start] == s[end] and (end - start <= 2 or palindrome[start + 1][end - 1])) {
                    palindrome[start][end] = true;
                    minimumCut = start == 0 ? 0 : min(minimumCut, dp[start - 1] + 1);
                }
            }
            dp[end] = minimumCut;
        } 
        return dp.back();
    }
};