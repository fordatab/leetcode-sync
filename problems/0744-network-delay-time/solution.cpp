class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto a : times) {
            adj[a[0]].push_back({a[1], a[2]});
        }
        vector<bool> v(n+1);
        vector<int> d(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        d[k] = 0;
        while (!pq.empty()) {
            auto [a, b] = pq.top();
            pq.pop();
            if (v[b]) {
                continue;
            }
            v[b] = true;
            for (auto [pt, dist] : adj[b]) {
                int new_dist = d[b] + dist;
                if (new_dist < d[pt]) {
                    d[pt] = new_dist;
                    pq.push({new_dist, pt});
                }
            }
        }
        int m = 0;
        for (int x = 1; x < n + 1; x++) {
            if (d[x] == INT_MAX) {
                return -1;
            }
            m = max(m, d[x]);
            cout << d[x] << " " << x << endl;
        }
        return m;
    }
};