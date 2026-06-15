class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        for (auto& row : grid) {
            sort(row.rbegin(), row.rend());
        }
        // if (k == 0) {
        //     return 0;
        // }
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < limits[i]; j++) {
                minHeap.push(grid[i][j]);

                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
        long long total = 0;
        while (!minHeap.empty()) {
            total += minHeap.top();
            minHeap.pop();
        } 
        return total;
    }
};