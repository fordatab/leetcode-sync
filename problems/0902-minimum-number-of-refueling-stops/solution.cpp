class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size(); 
        vector<long long> dp(n + 1);
        dp[0] = startFuel;
        for (int x = 0; x < n; x++) {
            // for each x in dp, find the max distance travelled with MAX x stops
            for (int i = x + 1; i >= 1; i--) {
                if (stations[x][0] <= dp[i-1]) {
                    dp[i] = max(dp[i], dp[i-1] + stations[x][1]);

                }
            }
        } 
        for (int x = 0; x < dp.size(); x++) {
            cout << dp[x] << " ";
            if (dp[x] >= target) {
                return x;
            }
        }
        return -1;
    }
};