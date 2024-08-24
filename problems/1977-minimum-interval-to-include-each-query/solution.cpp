class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(begin(intervals), end(intervals));
        vector<pair<int, int>> sorted_q(queries.size());
        for (int x = 0; x < queries.size(); x++) {
            sorted_q[x] = {queries[x], x};
        } 
        sort(begin(sorted_q), end(sorted_q));
        priority_queue<pair<int, int>, 
                vector<pair<int, int>>, 
                greater<pair<int, int>>> pq;
        
        vector<int> out(queries.size());
        int i = 0;
        unordered_map<int, int> m;
        for (int x = 0; x < queries.size(); x++) {
            while (i < intervals.size() && intervals[i][0] <= sorted_q[x].first) {
                pq.push({intervals[i][1] - intervals[i][0] + 1, intervals[i][1]});
                i++;
            }
            while (!pq.empty() && pq.top().second < sorted_q[x].first) {
                pq.pop();
            }
            m[sorted_q[x].second] = pq.empty() ? -1 : pq.top().first;
        }
        for (int x = 0; x < queries.size(); x++) {
            out[x] = m[x];
        }
        return out;
    }
};
