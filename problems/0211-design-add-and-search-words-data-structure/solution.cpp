class PrefixTreeNode {
public:
    PrefixTreeNode* children[26];
    bool isWord;
    
    PrefixTreeNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isWord = false;
    }
};

class WordDictionary {
private:
    PrefixTreeNode* root;
public:
    WordDictionary() {
        root = new PrefixTreeNode();
    }
    
    void addWord(string word) {
        PrefixTreeNode* t = root;
        for (char c : word) {
            if (t->children[c-'a'] == NULL) {
                t->children[c-'a'] = new PrefixTreeNode();
            }
            t = t->children[c-'a'];
        }
        t->isWord = true;
    }
                
    bool search(string word) {
        return dfs(word, 0, root);
    }
    
    bool dfs(string word, int j, PrefixTreeNode* root) {
        PrefixTreeNode* curr = root;
        for (int x = j; x < word.size(); x++) {
            if (word[x] == '.') {
                for (PrefixTreeNode * p : curr->children) {
                    if (p && dfs(word, x + 1, p)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (!curr->children[word[x]-'a']) {
                    return false;
                }
                curr = curr->children[word[x]-'a'];
            }
        }
        return curr->isWord;
    }
};
