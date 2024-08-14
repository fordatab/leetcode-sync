class Node {
public:
    string val;
    Node* prev;
    Node* next;

    Node(string v) : val(v), prev(nullptr), next(nullptr) {}
};
class BrowserHistory {
private:
    Node* history;
public:
    BrowserHistory(string homepage) {
        history = new Node(homepage);
    }
    
    void visit(string url) {
        Node* cur = history->next;
        Node* to_delete;
        while (cur) {
            to_delete = cur;
            cur = cur->next;
            delete to_delete;
        }
        history->next = new Node(url);
        history->next->prev = history;
        history = history->next;
    }
    
    string back(int steps) {
        Node* b = history;
        while (steps && b->prev) {
            b = b->prev;
            steps--;
        }
        history = b;
        return b->val;
    }
    
    string forward(int steps) {
        Node* f = history;
        while (steps && f->next) {
           f = f->next;
            steps--;
        }
        history = f;
        return f->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */