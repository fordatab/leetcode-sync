class Solution {
public:
    int numWays(int n, int k) {
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(3)));
        // for (int x = 0; x < k + 1; x++) {
        //     dp[1][x][1] = 1;
        //     dp[1][x][2] = 0;
        // }


        // for (int x = 2; x < n + 1; x++) {
        //     for (int y = 1; y < k + 1; y++) {
        //         // run length of 1. must create a new color from previous 
        //         int ct = 0;
        //         // look for all the colors in the previous fence where not the same and has 2 or 1 length
        //         for (int i = 1; i < k + 1; i++) {
        //             if (i != y) {
        //                 ct += dp[x-1][i][1];
        //                 ct += dp[x-1][i][2]; 
        //             }
        //         }
        //         dp[x][y][1] = ct;
        //         // run length of 2. continute previous color
        //         dp[x][y][2] = dp[x-1][y][1];  
        //     }
        // }
        // // for (int x = 0; x < n + 1; x++) {
        // //     for (int y = 0; y < k + 1; y++) {
        // //         cout << dp[x][y][1] << "," << dp[x][y][2] << " "; 
        // //     }
        // //     cout << endl;
        // // }

        // int out = 0;
        // for (int y = 1; y < k + 1; y++) {
        //     out += (dp[n][y][2] + dp[n][y][1]);
        // }
        // return out;
        // 0 is same 
        // 1 is diff
        vector<vector<int>> dp(n + 1, vector<int>(2));
        dp[1][0] = 0;
        dp[1][1] = k;
        for (int x = 2; x < n + 1; x++) {
            dp[x][0] = dp[x-1][1];
            dp[x][1] = (dp[x-1][0] + dp[x-1][1]) * (k - 1); 
        }
        return dp[n][0] + dp[n][1];
    }
};