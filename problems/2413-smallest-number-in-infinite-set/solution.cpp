class SmallestInfiniteSet {
private: 
    vector<bool> contains;
    int curr;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    SmallestInfiniteSet() {
        curr = 1;
        vector<bool> a(10002, false);
        contains = a;
    }
    
    int popSmallest() {
        if (pq.empty()) {
            int x = curr;
            curr++;
            return x;
        }
        int out = pq.top();
        contains[out] = false;
        pq.pop();
        return out;
    }
    
    void addBack(int num) {
        if (!contains[num] && curr > num) {
            pq.push(num);
            contains[num] = true;
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */