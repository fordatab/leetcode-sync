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

class Trie {
private:
    PrefixTreeNode* root;

public:
    Trie() {
        root = new PrefixTreeNode();
    }
    
    void insert(string word) {
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
        PrefixTreeNode* t = root;
        for (char c : word) {
            if (t->children[c-'a'] == NULL) {
                return false;
            }
            t = t->children[c-'a'];
        }
        return t->isWord;
    }
    
    bool startsWith(string prefix) {
        PrefixTreeNode* t = root;
        for (char c : prefix) {
            if (t->children[c-'a'] == NULL) {
                return false;
            }
            t = t->children[c-'a'];
        }
        return true;
    }
};
