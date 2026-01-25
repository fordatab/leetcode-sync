class Solution {
public:
    int minDifficulty(vector<int>& job, int d) {
        int n = (int)job.size();
        if (n < d) return -1;

        const int INF = 1e9;
        vector<vector<int>> dp(d + 1, vector<int>(n + 1, INF));
        dp[0][0] = 0;

        for (int day = 1; day <= d; ++day) {
            // i = number of jobs done so far
            for (int i = day; i <= n; ++i) {
                int mx = 0;
                // k = split point: previous days do k jobs, last day does jobs k..i-1
                for (int k = i - 1; k >= day - 1; --k) {
                    mx = max(mx, job[k]);              // max over job[k..i-1] as k moves left
                    dp[day][i] = min(dp[day][i], dp[day - 1][k] + mx);
                }
            }
        }

        return dp[d][n];
    }
};