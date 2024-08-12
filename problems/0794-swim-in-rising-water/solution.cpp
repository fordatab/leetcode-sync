class Solution {
private:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int out = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        vector<vector<int>> v(n, vector<int> (n));
        v[0][0] = true;
        while (!pq.empty()) {
            auto [a, b] = pq.top();
            auto [x, y] = b;
            pq.pop();
            if (x == n-1 && y == n-1) {
                return a;
            }
            for (int d = 0; d < 4; d++) {
                int i = x + dx[d];
                int j = y + dy[d];
                if (i >= 0 && j >= 0 && i < n && j < n && !v[i][j]) {
                    v[i][j] = true;
                    pq.push({max(a, grid[i][j]), {i, j}});
                }
            }
        }
        return -1;
    }
};
