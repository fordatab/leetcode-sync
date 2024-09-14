class CustomStack {
private:
    int max_sz;
    vector<int> stk;
public:
    CustomStack(int maxSize) {
        max_sz = maxSize;
    }
    
    void push(int x) {
        if (stk.size() < max_sz) {
            stk.push_back(x);
        }
    }
    
    int pop() {
        if (stk.empty()) {
            return -1;
        }
        int t = stk.back();
        stk.pop_back();
        return t;
    }
    
    void increment(int k, int val) {
        if (stk.size() < k) {
            k = stk.size();
        }
        for (int x = 0; x < k; x++) {
            stk[x] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */