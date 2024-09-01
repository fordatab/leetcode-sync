class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (original.size() != m *n ) {
            return {};
        }
        vector<vector<int>> out (m, vector<int> (n));
        for (int x = 0; x < original.size(); x++) {
            out[x/n][x%n] = original[x];
        }
        return out;

    }
};