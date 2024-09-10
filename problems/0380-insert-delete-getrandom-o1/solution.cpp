class RandomizedSet {
private:
    vector<int> n;
    unordered_map<int, int> m;
public:
    bool insert(int val) {
        if (m.find(val) != m.end()) {
            return false;
        }
        n.push_back(val);
        m[val] = n.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if (m.find(val) == m.end()) {
            return false;
        }
        int last = n.back();
        m[last] = m[val];
        n[m[val]] = last;
        n.pop_back();
        m.erase(val);

        return true;
    }
    
    int getRandom() {
        return n[rand() % n.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */