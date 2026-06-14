class LRUCache {
public:

    struct Node {
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}

    };
    int cap;
    unordered_map<int, Node*> map;

    Node* head;
    Node* tail;


    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->prev = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()) {
            return -1;
        }

        Node* used = map[key];
        // remove
        Node* prev = used->prev;
        Node* next = used->next;
        prev->next = next;
        next->prev = prev;
        // add to front
        Node* front = head->prev;
        front->next = used;
        used->prev = front;
        used->next = head;
        head->prev = used; 
        return used->val;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            Node* used = map[key];
            Node* prev = used->prev;
            Node* next = used->next;
            prev->next = next;
            next->prev = prev;
        }
        Node* node = new Node(key, value);
        map[key] = node;
        // add to front
        Node* front = head->prev;
        front->next = node;
        node->prev = front;
        node->next = head;
        head->prev = node; 

        if (map.size() > cap) {
            Node* lru = tail->next;
            map.erase(lru->key);
            Node* prev = lru->prev;
            Node* next = lru->next;
            prev->next = next;
            next->prev = prev;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */