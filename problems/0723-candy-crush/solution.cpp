class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        bool crushed = true;
        while (crushed) {
            // mark
            map<pair<int, int>, int> marked; 
            for (int x = 0; x < board.size(); x++) {
                for (int y = 0; y < board[0].size(); y++) {
                    if (board[x][y] == 0) continue;

                    vector<pair<int, int>> m;
                    int start = board[x][y];
                    int i = x;
                    m.push_back({x, y});
                    while (i + 1 < board.size() and board[i + 1][y] == start) {
                        i++;
                        m.push_back({i, y});
                    }
                    if (m.size() >= 3) {
                        for (auto p : m) {
                            marked[p]++;
                        }
                    }
                    vector<pair<int, int>> f;
                    int j = y;
                    f.push_back({x, y});
                    while (j + 1 < board[0].size() and board[x][j + 1] == start) {
                        j++;
                        f.push_back({x, j});
                    }
                    if (f.size() >= 3) {
                        for (auto p : f) {
                            marked[p]++;
                        }
                    }
                }
            }
            if (marked.size()) {
                for (int y = 0; y < board[0].size(); y++) {
                    int write = board.size() - 1;
                    for (int x = board.size() - 1; x >= 0; x--) {
                        if (!marked.count({x, y})) {
                            board[write--][y] = board[x][y];
                        }
                    }
                    // fill the rest with zeros
                    while (write >= 0) {
                        board[write--][y] = 0;
                    }
                }
            } else {
                return board;
            }
        }
        return board;
    }
};