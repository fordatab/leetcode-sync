class Solution {
private:
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> v(m, vector<bool>(n));
        unordered_set<int> c;
        vector<vector<bool>> s(m, vector<bool>(n));

        for (int x = 0; x < m; x++) {
            for (int y = 0; y < n; y++) {
                if (board[x][y] == 'O' && !v[x][y]) {
                    if (dfs(board, v, c, x, y, m, n)) {
                        cout << "n " << endl;
                        for (auto a : c) {
                            int i = a/n;
                            int j = a - (i*n);
                            board[i][j] = 'X';
                        }
                    }
                    c.clear();
                }
            }
        }
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& v, unordered_set<int>& c, int x, int y, int m, int n) {
        v[x][y] = true;
        cout << x << " FIRST " << y << endl;
        bool out = true;
        c.insert(x*n + y);
        for (int d = 0; d < 4; d++) {
            int i = x + dx[d];
            int j = y + dy[d];
            if (i < 0 || j < 0 || i == m || j == n) {
                return false;
            }
            if (board[i][j] == 'X') {
                continue;
            }
            cout << i << " " << j << endl;
            if (i == 0 || j == 0 || i == m-1 || j == n-1) {
                if (board[i][j] != 'X') {
                    cout << " nigger" << endl;
                    out = false;
                }
                continue;

            }
            if (!v[i][j]) {
                c.insert(i*n + j);
                out &= dfs(board, v, c, i, j, m, n);
            }
        }
        return out;
    }
};
