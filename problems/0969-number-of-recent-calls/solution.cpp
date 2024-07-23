class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {
        queue<int> a = q;
    }
    
    int ping(int t) {
        while (!q.empty() && t - 3000 > q.front()) {
            if (t - 3000 > q.front()) {
                q.pop();
            }
        }
        q.push(t);
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */