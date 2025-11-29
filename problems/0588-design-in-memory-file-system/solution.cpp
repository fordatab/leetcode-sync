class FileSystem {
public:
    struct Node {
        string name;
        bool isPath;
        string fileContent;
        map<string, Node*> contents;
    };

    Node* root;

    FileSystem() {
        root = new Node();
        root->isPath = true; 
    }
    
    vector<string> ls(string path) {
        cout << "ls" << endl; 
        std::istringstream ss(path);
        std::string token;
        char delimiter = '/';
        Node* curr = root;
        // Optional: store tokens in a vector
        std::vector<std::string> tokens;

        while (std::getline(ss, token, delimiter)) {
            if (!token.empty()) {
                std::cout << "Extracted token: " << token << std::endl;
                // if (curr->contents[token] == nullptr) {
                //     // this means it is a file not a dir
                //     return {curr->name};
                // }
                curr = curr->contents[token];

            }
        }
        vector<string> out;
        if (curr->isPath) {
            for (auto [a, b] : curr->contents) {
                out.push_back(a);
            }
        } else {
            cout << curr->name << endl;
            out = {curr->name};
        }
        return out;

    }
    
    void mkdir(string path) {
        std::istringstream ss(path);
        std::string token;
        char delimiter = '/';
        Node* curr = root;
        // Optional: store tokens in a vector
        std::vector<std::string> tokens;

        while (std::getline(ss, token, delimiter)) {
            if (!token.empty()) {
                std::cout << "Extracted token: " << token << std::endl;
                if (curr->contents[token] == nullptr) {
                    curr->contents[token] = new Node();
                    curr->contents[token]->isPath = true;
                }
                curr = curr->contents[token];
            }
        }
    }
    
    void addContentToFile(string path, string content) {
        std::istringstream ss(path);
        std::string token;
        char delimiter = '/';
        Node* curr = root;
        // Optional: store tokens in a vector
        std::vector<std::string> tokens;

        while (std::getline(ss, token, delimiter)) {
            if (!token.empty()) {
                std::cout << "Extracted token: " << token << std::endl;
                if (curr->contents[token] == nullptr) {
                    curr->contents[token] = new Node();
                    curr->contents[token]->isPath = false;
                    curr->contents[token]->fileContent = content;
                    curr->contents[token]->name = token;
                    return;
                }
                curr = curr->contents[token];
            }
        }
        curr->fileContent += content;
    }
    
    string readContentFromFile(string path) {
        std::istringstream ss(path);
        std::string token;
        char delimiter = '/';
        Node* curr = root;
        // Optional: store tokens in a vector
        std::vector<std::string> tokens;

        while (std::getline(ss, token, delimiter)) {
            if (!token.empty()) {
                std::cout << "Extracted token: " << token << std::endl;
                curr = curr->contents[token];
            }
        }
        return curr->fileContent;
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */