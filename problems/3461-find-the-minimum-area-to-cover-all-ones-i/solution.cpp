class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int min_i = INT_MAX;
        int max_i = INT_MIN;
        int min_j = INT_MAX;
        int max_j = INT_MIN;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    min_i = min(i, min_i);
                    max_i = max(i, max_i);
                    min_j = min(j, min_j);
                    max_j = max(j, max_j);
                }
            }
        }
        return (max_i - min_i + 1) * (max_j - min_j + 1);
    }
};