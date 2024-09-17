class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int x =  n - 1;
        int y = 0;
        while (x > -1 && y < m) {
            if (matrix[y][x] == target) {
                return true;
            }
            if (matrix[y][x] > target) {
                x--;
            } else {
                y++;
            }
        }
        return false;
    }
};