class Solution {
public:
    static bool comp(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
    }
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), comp);
        for (auto m : meetings) {
            cout << m[0] << " " << m[1]; 
        }
        priority_queue<int, vector<int>, greater<int>> free;
        for (int x = 0; x < n; x++) {
            free.push(x);
        }
priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> ends;
        vector<int> freq(n);
        for (auto m : meetings) {
            int start = m[0];
            int end = m[1];
            while (ends.size() and ends.top().first <= start) {
                free.push(ends.top().second);
                ends.pop();

            }
            if (free.size()) {
                int room = free.top();
                freq[room]++;
                free.pop();
                ends.push({end, room});
            } else {
                auto [earliest_end, room] = ends.top();
                ends.pop();  // Must pop!
                freq[room]++;  // Must increment frequency!
                long long new_end = max((long long)earliest_end, (long long)start) + (end - start);
                ends.push({new_end, room});            
            }
        }
        int m = -1;
        int idx = 0;
        for (int x = 0; x < n; x++) {
            if (freq[x] > m) {
                idx = x;
                m = freq[x];
            }
        }
        return idx; 
    }
};