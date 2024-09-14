class Solution {
public:
    void gameOfLife(vector<vector<int>>& b) {
        int m = b.size();
        int n = b[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int c = 0;
                for (int x = max(i-1, 0); x < min(i+2, m); x++) {
                    for (int y = max(j-1, 0); y < min(j+2, n); y++) {
                        c += b[x][y] & 1;
                    }
                }
                c-= b[i][j] & 1;
                if (b[i][j] & 1) {
                    if (c == 2 || c == 3) {
                        b[i][j] |= 2;

                    }
                    if (c > 4) {
                        // do noting
                    }
                } else {
                    if (c == 3) {
                                                b[i][j] |= 2;

                    }  else {
                        // do nothing
                    }
                }

            }
        }
        for (auto & r : b) {
            for (auto & c : r) {
                c >>= 1;
            }
        }

    }
};