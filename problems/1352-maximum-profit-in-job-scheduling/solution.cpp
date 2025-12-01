class Solution {
public:
    struct Job {
        int start, end, profit;
    };
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job> jobs;
        int n = startTime.size();
        for (int x = 0; x < n; x++) {
            jobs.push_back({startTime[x], endTime[x], profit[x]});
        } 
        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.end < b.end;
        });    

        vector<int> dp(n);
        dp[0] = jobs[0].profit;
        sort(endTime.begin(), endTime.end());

        // profit from 0th job is taking the 0th profit
        for (int x = 1; x < n; x++) {
            // take the job. look for the latest ending job that ends before the start of the job we just took
            int takeJob = jobs[x].profit;
            int start = jobs[x].start; 
            int idx = upper_bound(endTime.begin(), endTime.end(), start) - endTime.begin() - 1;
            if (idx >= 0) {
                takeJob += dp[idx];
            } 

            int pass = dp[x-1];
            dp[x] = max(pass, takeJob);
        }
        return dp[n-1]; 
    }

};