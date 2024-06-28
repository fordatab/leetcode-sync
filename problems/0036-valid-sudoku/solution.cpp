class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                int box[9] = {0};
                for (int z = 0; z < 3; z++) {
                    for (int i = 0; i < 3; i++) {
                        int index = 3 * x + z;
                        if (board[3*x + z][3*y + i] != '.') {
                            box[board[3*x + z][3*y + i] - '1']++;
                        }
                    }
                }
                for (int l = 0; l < 9; l++) {
                    if (box[l] > 1) {
                        return false;
                    }
                }
            }
        }
        for (int x = 0; x < 9; x++) {
            int col[9] = {0};
            int row[9] = {0};
            for (int y = 0; y < 9; y++) {
                if (board[x][y] != '.') {
                    col[board[x][y]-'1']++;
                }
                if (board[y][x] != '.') {
                    row[board[y][x]-'1']++;
                }
            }
            for (int l = 0; l < 9; l++) {
                if (row[l] > 1 || col[l] > 1) {
                    return false;
                }
            }
        }
        return true;
    }
};
