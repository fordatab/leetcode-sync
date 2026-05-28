class Solution {
<<<<<<< HEAD
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int x = 0; x < board.size(); x++) {
            for (int y = 0; y < board[0].size(); y++) {
                if (board[x][y] == word[0]) {
                    if (dfs(board, word, 0, x, y, board.size(), board[0].size())) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int index, int i, int j, int m, int n) {
 
        if (i >= m || j >= n || j < 0|| i < 0 || word[index] != board[i][j]) {
            return false;
        }
                if (index == word.size()-1) {
            return true;

        }  
        board[i][j] = '#';
        if (dfs(board, word, index+1, i+1, j, m, n) ||
            dfs(board, word, index+1, i, j+1, m, n) ||
            dfs(board, word, index+1, i-1, j, m, n) ||
            dfs(board, word, index+1, i, j-1, m, n)) {
            return true;
        }
        board[i][j] = word[index];
        return false;
    }
};
=======
private:
    vector<vector<char>> board;
    int ROWS;
    int COLS;

public:
    bool exist(vector<vector<char>>& board, string word) {
        this->board = board;
        ROWS = board.size();
        COLS = board[0].size();
        for (int row = 0; row < ROWS; ++row)
            for (int col = 0; col < COLS; ++col)
                if (backtrack(row, col, word, 0)) return true;
        return false;
    }

protected:
    bool backtrack(int row, int col, const string& word, int index) {
        /* Step 1). check the bottom case. */
        if (index >= word.length()) return true;
        /* Step 2). Check the boundaries. */
        if (row < 0 || row == ROWS || col < 0 || col == COLS ||
            board[row][col] != word[index])
            return false;
        /* Step 3). explore the neighbors in DFS */
        bool ret = false;
        // mark the path before the next exploration
        board[row][col] = '#';
        int rowOffsets[4] = {0, 1, 0, -1};
        int colOffsets[4] = {1, 0, -1, 0};
        for (int d = 0; d < 4; ++d) {
            ret = backtrack(row + rowOffsets[d], col + colOffsets[d], word,
                            index + 1);
            if (ret) break;
        }
        /* Step 4). clean up and return the result. */
        board[row][col] = word[index];
        return ret;
    }
};
>>>>>>> 3440cedbebbd4694a83e579928aecd0b6ec10f2d
