class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        for (auto& row : grid) {
            sort(row.rbegin(), row.rend());
        }
        vector<int> combined;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < limits[i]; j++) {
                combined.push_back(grid[i][j]);
            }
        }
        sort(combined.rbegin(), combined.rend());
        long long total = 0;
        for (int i = 0; i < k; i++) {
            total += combined[i];
        }  
        return total;
    }
};