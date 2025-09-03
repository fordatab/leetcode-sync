class FileSystem {
public:
    struct Node {
        unordered_map<string, Node*> m;
        int val;
        Node(int v = -1) : val(v) {}  // default -1, or supply a value
    };

    Node* root;

    FileSystem() {
        root = new Node();
    }
    vector<string> tokenize(const string& path) {
        vector<string> tokens;
        stringstream ss(path);
        string item;

        while (getline(ss, item, '/')) {
            if (!item.empty()) {   // skip empty (because path starts with '/')
                tokens.push_back(item);
            }
        }
        return tokens;
    }
    bool createPath(string path, int value) {
        auto cpy = root;
        vector<string> parts = tokenize(path);
        for (int x = 0; x < parts.size(); x++) {
            if (x == parts.size() - 1) {
                if (!cpy->m.count(parts[x])) {
                    cpy->m[parts[x]] = new Node(value);
                    return true;
                } else {
                    return false;
                } 
            } else {
                if (!cpy->m.count(parts[x])) {
                    return false;
                } else {
                    cpy = cpy->m[parts[x]];
                }
            }

        }
        return true;
    }
    
    int get(string path) {
        auto cpy = root;
        vector<string> parts = tokenize(path);
        for (int x = 0; x < parts.size(); x++) {
            if (!cpy->m.count(parts[x])) {
                return -1;
            }
            cpy = cpy->m[parts[x]];
        }
        return cpy->val;

    }
};
