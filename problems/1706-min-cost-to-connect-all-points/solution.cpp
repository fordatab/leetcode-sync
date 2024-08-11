class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<pair<int, int>>> adj(points.size());
        for (int x = 0; x < points.size(); x++) {
            for (int y = 0; y < points.size(); y++) {
                int dist = abs(points[x][0] - points[y][0]) + abs(points[x][1] - points[y][1]);
                adj[x].push_back({y, dist});
            }
        }
        unordered_set<int> v;
        int out = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (v.size() < points.size()) {
            auto [a, b] = pq.top();
            pq.pop();
            if (v.count(b)) {
                continue;
            }
            out += a;
            v.insert(b);
            for (auto [pt, dist] : adj[b]) {
                if (!v.count(pt)) {
                    pq.push({dist, pt});
                }
            }
        }
        return out;
    }
};
