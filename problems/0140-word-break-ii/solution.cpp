class Solution {
public:
    struct TrieNode {
        bool isWord;
        unordered_map<char, TrieNode*> children;
    };

    void bt(TrieNode* root, vector<string>& out, string cur, vector<string>& wordDict, int i, vector<int>& dp, string s) {
        if (i == s.size()) {
            cur.pop_back();
            out.push_back(cur);
            return;
        }
        TrieNode* curr = root;
        string word; 
        for (int j = i; j < s.size(); j++) {
            char c = s[j];
            if (curr->children[c] == nullptr) {
                return;
            } 
            cout << c << endl;
            word.push_back(c);
            curr = curr->children[c];
            if (curr->isWord and dp[i] == 1) {
                cur += word + " ";
                dp[j+1] = 1;
                // cout << cur << endl;
                bt(root, out, cur, wordDict, j + 1, dp, s);
                cur = cur.substr(0, cur.size() - word.size() - 1); 
            } 
        } 
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        TrieNode* root = new TrieNode();
        for (auto w : wordDict) {
            TrieNode* curr = root;
            for (char c : w) {
                if (curr->children[c] == nullptr) {
                    curr->children[c] = new TrieNode();
                }
                curr = curr->children[c];
            }
            curr->isWord = true;
        }
        vector<string> out;
        string cur;
        vector<int> dp(s.size() + 1);
        dp[0] = 1;
        bt(root, out, cur, wordDict, 0, dp, s);
        return out;
    }
};