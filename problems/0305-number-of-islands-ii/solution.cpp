class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int N = m * n;
        vector<int> parent(N, -1), rank(N, 0);
        int islands = 0;

        function<int(int)> find = [&](int x) -> int {
            if (parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        };

        auto unite = [&](int a, int b) -> bool {
            int ra = find(a), rb = find(b);
            if (ra == rb) return false;              // already same component
            if (rank[ra] < rank[rb]) swap(ra, rb);
            parent[rb] = ra;
            if (rank[ra] == rank[rb]) rank[ra]++;
            return true;                             // actually merged
        };

        vector<int> ans;
        ans.reserve(positions.size());
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto &p : positions) {
            int x = p[0], y = p[1];
            int id = x * n + y;

            if (parent[id] != -1) {                  // duplicate add
                ans.push_back(islands);
                continue;
            }

            parent[id] = id;                         // make new land
            islands++;

            for (auto &d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
                int nid = nx * n + ny;
                if (parent[nid] == -1) continue;     // water
                if (unite(id, nid)) islands--;        // only decrement on real merge
            }

            ans.push_back(islands);
        }

        return ans;
    }
};