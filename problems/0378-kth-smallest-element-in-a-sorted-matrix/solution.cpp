class Solution {
public:
    int kthSmallest(vector<vector<int>>& m, int k) {
        auto comp = [&m](pair<int, int>& a, pair<int, int>& b) {
            return m[a.first][a.second] > m[b.first][b.second];
        };

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);

        int n = m.size();
        for (int i = 0; i < min(n, k); i++) {
            pq.push({i, 0});
        }
        
        while (k > 1) {
            auto [i, j] = pq.top();
            pq.pop();
            
            if (j + 1 < m[i].size()) {
                pq.push({i, j + 1});
            }
            
            k--;
        }
        
        return m[pq.top().first][pq.top().second];
    }
};