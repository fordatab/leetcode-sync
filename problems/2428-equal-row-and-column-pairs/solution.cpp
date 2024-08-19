class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> m;
        int n = grid.size();
        int out = 0;
        for (int x = 0; x < n; x++) {
            string s;
            for (int y = 0; y < n; y++) {
                s += to_string(grid[x][y]) + "#";
            }
            m[s]++;
        }
        for (int y = 0; y < n; y++) {
            string s;
            for (int x = 0; x < n; x++) {
                s += to_string(grid[x][y]) + "#";
            }
            out += m[s];
        }
        return out;

    }
};