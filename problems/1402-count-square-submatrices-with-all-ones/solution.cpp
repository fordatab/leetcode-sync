class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1));
        int out = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    dp[i+1][j+1] = min({dp[i+1][j], dp[i][j+1], dp[i][j]}) + 1;
                    out = max(out, dp[i+1][j+1]);
                }
            }
        }
        int t = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                t += dp[i][j];
            }
        }
        return t;
    }
};


// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int m = matrix.size();
//         int n = matrix[0].size();
//         vector<vector<int>> dp(m + 1, vector<int> (n + 1));
//         int out = 0;
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (matrix[i][j] == '1') {
//                     dp[i+1][j+1] = min({dp[i+1][j], dp[i][j+1], dp[i][j]}) + 1;
//                     out = max(out, dp[i+1][j+1]);
//                 }
//             }
//         }
//         return out * out;
//     }
// };