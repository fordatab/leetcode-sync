class Solution {
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
