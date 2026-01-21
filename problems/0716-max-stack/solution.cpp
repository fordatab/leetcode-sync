class MaxStack {
public:
    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int v = 0) : val(v), next(nullptr), prev(nullptr) {}
    };
    
    Node* head;
    Node* tail;
    set<pair<int, Node*>> s;

    MaxStack() {
        head = new Node(); // fixed sentinel head
        tail = new Node(); // fixed sentinel tail  
        head->next = tail;
        tail->prev = head;
    }
    
    void push(int x) {
        Node* node = new Node(x);
        // Insert just before tail (growing to the right)
        node->next = tail;
        node->prev = tail->prev;
        tail->prev->next = node;
        tail->prev = node;
        
        s.insert({x, node});
    }
    
    int pop() {
        Node* node = tail->prev; // top is before tail
        int val = node->val;
        
        // Remove from linked list
        tail->prev = node->prev;
        node->prev->next = tail;
        
        // Remove from set
        s.erase({val, node});
        delete node;
        return val;
    }
    
    int top() {
        return tail->prev->val; // top is before tail
    }
    
    int peekMax() {
        return s.rbegin()->first;
    }
    
    int popMax() {
        auto it = s.end();
        it--;
        int val = it->first;
        Node* node = it->second;
        
        // Remove from linked list (works anywhere in list)
        node->prev->next = node->next;
        node->next->prev = node->prev;
        
        // Remove from set
        s.erase(it);
        delete node;
        return val;
    }
};