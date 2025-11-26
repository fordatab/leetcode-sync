class Solution {
public:
    struct TrieNode{
        unordered_map<string, TrieNode*> children;
        bool Isroot;
        TrieNode() : Isroot(false) {}

    };
    void dfs(vector<string>& out, vector<string>& cur, TrieNode* root) {
        if (root->Isroot) {
            string full;  
            for (string c : cur) {
                full += "/" + c;
            }
            out.push_back(full);
            return;
        }
        for (auto [a, b] : root->children) {
            if (b != nullptr) {
                cur.push_back(a);
                dfs(out, cur, b);
                cur.pop_back();
            }
        }
    }
    vector<string> removeSubfolders(vector<string>& folder) {
        TrieNode* root = new TrieNode();
        for (string s : folder) {
            TrieNode* curr = root;
            stringstream ss(s);
            char delim = '/';
            string seg;
            while (getline(ss, seg, delim)) {
                if (seg.empty()) continue; // skip leading segment from '/'
                if (curr->Isroot) break;     // parent folder already stored
                if (curr->children[seg] == nullptr) {
                    curr->children[seg] = new TrieNode();
                }
                curr = curr->children[seg];
            }
            curr->Isroot = true;
        }
        vector<string> out;
        vector<string> cur;
        dfs(out, cur, root);
        return out;
    }
};