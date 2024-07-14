class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int total = 0;
        for (int x = 0; x < grid.size(); x++) {
            int idx = 0;
            vector<int> arr = grid[x];
            int l = 0;
            int r = arr.size() - 1;
            while (l <= r) {
                int mid = (r - l)/2 + l;
                // if (arr[mid] == 0) {
                //     idx = mid;
                //     break;
                // }
                if (arr[mid] >= 0) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
            if (l > r) {
                idx = r;
            }
            total += arr.size() - idx - 1;
        }
        return total;
    }
};