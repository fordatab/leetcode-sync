class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> min_row;
        vector<int> max_col;
        for (auto a : matrix) {
            cout << *min_element(begin(a), end(a)) << endl;
            min_row.push_back(*min_element(begin(a), end(a)));
        }
        for (int x = 0; x < matrix[0].size(); x++) {
            int m = 0;
            for (int y = 0; y < matrix.size(); y++) {
                m = max(m, matrix[y][x]);
            }
            cout << m << endl;
            max_col.push_back(m);
        }
        unordered_map<int, int> m;
        for (int a : max_col) {
            m[a]++;
        }
        for (int a : min_row) {
            m[a]++;
        }
        vector<int> out;
        for (auto a : m) {
            if (a.second > 1) {
                out.push_back(a.first);
            }
        }
        return out;
    }
};