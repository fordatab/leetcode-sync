class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0;
        int r = matrix.size() * matrix[0].size() - 1;
        while (l <= r) {
            int mid = (r - l)/2 + l;
            int x = mid / matrix[0].size();
            int y = mid % matrix[0].size();
            if (matrix[x][y] == target) {
                return true;
            }
            if (matrix[x][y] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return false;
    }
};
