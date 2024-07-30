class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows + 1, vector<int> (1, 1));
        dp[1] = {1};
        for (int x = 2; x < numRows + 1; x++) {
            cout << "a" << endl;
            cout << dp[x-1].size() - 1 << endl;
            for (int y = 0; y < dp[x-1].size() - 1; y++) {
                cout << "fag" << endl;
                dp[x].push_back(dp[x-1][y] + dp[x-1][y+1]);
            }
            dp[x].push_back(1);
            cout << "b" << endl;
        } 
        return vector<vector<int>>(dp.begin() + 1, dp.end());
    }
};