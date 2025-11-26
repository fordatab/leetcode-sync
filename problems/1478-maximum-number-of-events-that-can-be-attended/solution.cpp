class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        int out = 0;
        int lastDay = 0;
        for (auto &e : events) {
            lastDay = max(lastDay, e[1]);
        }
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        for (int day = 1; day <= lastDay; day++) {
            while (i < events.size() and events[i][0] == day) {
                pq.push(events[i][1]);
                i++;
            }
            while (pq.size() and pq.top() < day) {
                pq.pop();
            }
            if (pq.size()) {
                pq.pop();
                out++;
            }

        }
        // cout << prev << endl;
        return out;
    }
};