class Solution {
private:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> out;

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (bfs(heights, x, y, m , n)) {
                    out.push_back({x, y});
                }
            }
        }
        return out;
    }

    bool bfs(vector<vector<int>>& heights, int x, int y, int m, int n) {
        queue<pair<int, int>> q;
        q.push({x, y});
        unordered_set<int> v;
        v.insert(x*n+y);
        bool pac = false;
        bool atl = false;
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int i = p.first + dx[d];
                int j = p.second + dy[d];
                if (i < 0 || j < 0) {
                    pac = true;
                    if (atl) return true;
                    continue;
                }
                if (i == m || j == n) {
                    atl = true;
                    if (pac) return true;
                    continue;
                }
                if (v.count(i*n+j)) {
                    continue;
                }
                if (i >= 0 && j >= 0 && i < m && j < n && heights[p.first][p.second] >= heights[i][j]) {
                    q.push({i, j});
                    v.insert(i*n+j);
                }
            }
        }
        return pac && atl;
    }
};