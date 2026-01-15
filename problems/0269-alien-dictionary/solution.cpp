class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> adj;
        unordered_map<char, bool> v;
        for (string w : words) {
            for (char c : w) {
                adj[c];
            } 
        }

        for (int x = 0; x < words.size() -1 ; x++) {
            string w1 = words[x];
            string w2 = words[x+1];
            int minLen = min(w1.size(), w2.size());
            if (w1.length() > w2.length() && w1.substr(0, minLen) == w2.substr(0, minLen)) {
                return "";
            }
            for (int i = 0; i < minLen; i++) {
                if (w1[i] != w2[i]) {
                    adj[w1[i]].push_back(w2[i]);
                    break;
                }
            }
        }
        string s;
        for (auto [a, b] : adj) {
            if (dfs(adj, v, a, s)) {
                return "";
            }
        }
        reverse(begin(s), end(s));
        return s;

    }

    bool dfs(unordered_map<char, vector<char>>& adj, unordered_map<char, bool>& v, char c, string& r) {
        if (v.find(c) != v.end()) {
            return v[c];
        }
        v[c] = true;
        for (auto n : adj[c]) {
            if (dfs(adj, v, n, r)) {
                return true;
            }
        }

        v[c] = false;
        r.push_back(c);
        return false;
    }
};
