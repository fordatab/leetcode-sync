class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& matrix) {
        int m = matrix.size();        // rows
        int n = matrix[0].size();     // cols

        vector<vector<char>> res(n, vector<char>(m));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][m - 1 - i] = matrix[i][j];
            }
        }

        for (int x = 0; x < m; x++) {
            int ct = 0;
            for (int y = 0; y < n; y++) {
                if (res[y][x] == '#') {
                    ct++;
                    res[y][x] = '.';
                } else if (res[y][x] == '*') {
                    for (int i = y - 1; i > y - 1 - ct; i--) {
                        cout << i << endl;
                        res[i][x] = '#';
                    }
                    ct = 0;
                    continue;
                } 
                if (y == n - 1) {
                    for (int i = y; i > y - ct; i--) {
                        cout << i << endl;

                        res[i][x] = '#';
                    }
                }
                cout << ct  <<endl;
                
            }
        }
        return res;
    }
};