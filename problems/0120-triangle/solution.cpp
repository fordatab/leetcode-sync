class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m + 1, vector<int> (m));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < i + 1; j++) {
                cout << i << " " << j << " " << triangle[i][j] << endl;
                if (!j) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j];
                } else if (j == i) {
                    dp[i][j] = triangle[i][j] + dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
                }
                cout << dp[i][j] << endl;
            }
        }
        int o = INT_MAX;
        for (auto a : dp[m-1]) {
            cout << a << endl;
            o = min(o, a);
        }
        return o;
    }
};