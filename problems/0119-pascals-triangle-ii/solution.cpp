class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex;
        vector<vector<int>> dp(numRows + 2, vector<int> (1, 1));
        for (int x = 2; x < numRows + 2; x++) {
            for (int y = 0; y < dp[x-1].size() - 1; y++) {
                dp[x].push_back(dp[x-1][y] + dp[x-1][y+1]);
            }
            dp[x].push_back(1);
        } 
        return dp[rowIndex+1];
    }
};