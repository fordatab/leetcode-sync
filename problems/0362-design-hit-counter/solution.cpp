class HitCounter {
public:
    deque<int> q;

    void hit(int timestamp) {
        // push at back (timestamps increasing)
        q.push_back(timestamp);
    }
    
    int getHits(int timestamp) {
        // remove hits older than 300 seconds
        while (!q.empty() && q.front() <= timestamp - 300) {
            q.pop_front();
        }
        return q.size();
    }
};
