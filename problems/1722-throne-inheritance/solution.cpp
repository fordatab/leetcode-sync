class ThroneInheritance {
public:
    struct Node {
        string val;
        bool alive;
        vector<Node*> children;
        
        // Constructor
        Node(string v, bool a = true) : val(v), alive(a) {}
    }; 

    Node* root;
    unordered_map<string, Node*> m;



    ThroneInheritance(string kingName) {
        root = new Node(kingName);
        m[kingName] = root;
    }
    
    void birth(string parentName, string childName) {
        Node* child = new Node(childName);
        m[childName] = child;
        m[parentName]->children.push_back(child);
    }
    
    void death(string name) {
        m[name]->alive = false;
    }
    
    void dfs(vector<string>& order, Node* root) {
        if (!root) {
            return;
        }
        if (root->alive) {
            order.push_back(root->val);
        }
        for (auto n : root->children) {
            dfs(order, n);
        }
    }

    vector<string> getInheritanceOrder() {
        vector<string> out;
        dfs(out, root);
        return out;
    }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */