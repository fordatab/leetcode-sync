class Solution {
public:
    struct Job {
        int start, end, profit;
    };

    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        vector<Job> jobs(n);

        for (int x = 0; x < n; x++) {
            jobs[x] = {events[x][0], events[x][1], events[x][2]};
        } 
        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.end < b.end;
        });   
        vector<int> endTime(n);
        for (int x = 0; x < n; x++) {
            endTime[x] = jobs[x].end;
        }
        sort(endTime.begin(), endTime.end());
        vector<vector<int>> dp(n, vector<int> (k + 1));
        for (int y = 1; y <= k; y++) {
            dp[0][y] = jobs[0].profit;
        }
        for(int x = 1; x < n; x++) {
            for (int y = 0; y < k + 1; y++) {
                int takeJob = 0;
                if (y > 0) {
                    takeJob = jobs[x].profit;
                    int start = jobs[x].start;
                    int idx = lower_bound(endTime.begin(), endTime.end(), jobs[x].start) - endTime.begin() - 1;
                    if (idx >= 0) {
                        takeJob += dp[idx][y-1];
                    } 
                }
                int pass = dp[x-1][y];
                dp[x][y] = max(takeJob, pass);
            }
        }
        return dp[n-1][k];

    }
};

