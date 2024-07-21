class TrieNode {
public:
    map<char, TrieNode*> children;
    bool isWord = false;
    int refs = 0;

    void addWord(string word) {
        TrieNode* cur = this;
        cur->refs++;
        for (char c : word) {
            if (cur->children.count(c) == 0) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
            cur->refs++;
        }
        cur->isWord = true;
    }

    void removeWord(string word) {
        TrieNode* cur = this;
        cur->refs--;
        for (char c : word) {
            if (cur->children.count(c) > 0) {
                cur = cur->children[c];
                cur->refs--;
            }
        }
    }
};

class Solution {
public:
    int ROWS, COLS;

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        unordered_set<string> res;
        unordered_set<string> visit;
        TrieNode* root = new TrieNode();

        for (string& w : words) {
            root->addWord(w);
        }

        ROWS = board.size();
        COLS = board[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                dfs(r, c, root, "", board, res, visit, root);
            }
        }

        return vector<string>(res.begin(), res.end());
    }

private:
    void dfs(int r, int c, TrieNode* node, string word, vector<vector<char>>& board,
             unordered_set<string>& res, unordered_set<string>& visit, TrieNode* root) {
        if (
                r < 0 || r >= ROWS ||
                        c < 0 || c >= COLS ||
                        node->children.count(board[r][c]) == 0 ||
                        node->children[board[r][c]]->refs < 1 ||
                        visit.count(to_string(r) + "," + to_string(c)) > 0
        ) {
            return;
        }

        visit.insert(to_string(r) + "," + to_string(c));
        node = node->children[board[r][c]];
        word += board[r][c];
        if (node->isWord) {
            node->isWord = false;
            res.insert(word);
            root->removeWord(word);
        }

        dfs(r + 1, c, node, word, board, res, visit, root);
        dfs(r - 1, c, node, word, board, res, visit, root);
        dfs(r, c + 1, node, word, board, res, visit, root);
        dfs(r, c - 1, node, word, board, res, visit, root);
        visit.erase(to_string(r) + "," + to_string(c));
    }
};
