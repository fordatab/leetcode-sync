class Solution {
public:
    // Optimized check: Does character 'c' exist in the current row, col, or box?
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            // Check Row
            if (board[row][i] == c) return false;
            
            // Check Column
            if (board[i][col] == c) return false;
            
            // Check 3x3 Box
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;
        }
        return true;
    }

    bool bt(vector<vector<char>>& board, int x, int y) {
        // If we reached the end of the rows, we are done
        if (x == 9) {
            return true;
        }
        // If we reached the end of a column, move to next row
        if (y == 9) {
            return bt(board, x + 1, 0);
        }

        // If cell is already filled, skip it
        if (board[x][y] != '.') {
            return bt(board, x, y + 1);
        }

        // Try numbers 1-9
        for (int i = 1; i <= 9; i++) {
            char c = i + '0';
            
            // Check validity BEFORE placing the number
            // This avoids modifying the board if the number is invalid
            if (isValid(board, x, y, c)) {
                board[x][y] = c;
                
                if (bt(board, x, y + 1)) {
                    return true;
                }
                
                // Backtrack
                board[x][y] = '.';
            }
        }
        
        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        bt(board, 0, 0);
    }
};