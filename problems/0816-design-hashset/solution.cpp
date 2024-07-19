class MyHashSet {
private:
    int set[10000001] = {};
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        set[key] = 1;
    }
    
    void remove(int key) {
        if (set[key]) {
            set[key]--;
        }
    }
    
    bool contains(int key) {
        return set[key] > 0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */