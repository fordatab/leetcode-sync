class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int> r;
        unordered_set<int> c;
        for (int x = 0; x < matrix.size(); x++) {
            for (int y = 0; y < matrix[0].size(); y++) {
                if (!matrix[x][y]) {
                    r.insert(x);
                    c.insert(y);
                }
            }
        }
        for (int x = 0; x < matrix.size(); x++) {
            for (int y = 0; y < matrix[0].size(); y++) {
                if (r.count(x) || c.count(y)) {
                    matrix[x][y] = 0;
                } 
            }
        }
    }
};