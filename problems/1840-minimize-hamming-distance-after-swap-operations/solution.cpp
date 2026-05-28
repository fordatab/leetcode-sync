class Solution {
private:
<<<<<<< HEAD
    vector<int> fa;
    vector<int> rank;
    // path compression
    int find(int x) {
        if (fa[x] != x) {
            fa[x] = find(fa[x]);
        }
        return fa[x];
=======
    vector<int> parent;
    vector<int> rank;
    // path compression
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
    }

    void Union(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        // merge by rank
        if (rank[x] < rank[y]) {
            swap(x, y);
        }
<<<<<<< HEAD
        fa[y] = x;
=======
        parent[y] = x;
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
        if (rank[x] == rank[y]) {
            rank[x]++;
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
                               vector<vector<int>>& allowedSwaps) {
        int n = source.size();
<<<<<<< HEAD
        fa.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            fa[i] = i;
        }
=======
        parent.resize(n);
        rank.resize(n, 0);
        iota(parent.begin(), parent.end(), 0);

>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
        for (auto& pair : allowedSwaps) {
            Union(pair[0], pair[1]);
        }
        unordered_map<int, unordered_map<int, int>> sets;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            sets[f][source[i]]++;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int f = find(i);
            if (sets[f][target[i]] > 0) {
                sets[f][target[i]]--;
            } else {
                ans++;
            }
        }
        return ans;
    }
};