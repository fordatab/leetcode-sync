class Solution {
public:
    int totalNQueens(int n) {
        unordered_set<int> col;
        unordered_set<int> posDiag;
        unordered_set<int> negDiag;
        int t;
        vector<string> board(n, string(n, '.'));

        backtrack(0, n, col, posDiag, negDiag, board, t);
        return t;
    }
private:
    void backtrack(int r, int n, unordered_set<int>& col, unordered_set<int>& posDiag,
                   unordered_set<int>& negDiag, vector<string>& board,
                   int& t) {
        if (r == n) {
            t++;
            return;
        }

        for (int c = 0; c < n; c++) {
            if (col.count(c) || posDiag.count(r + c) || negDiag.count(r - c)) {
                continue;
            }

            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);
            board[r][c] = 'Q';

            backtrack(r + 1, n, col, posDiag, negDiag, board, t);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }
};