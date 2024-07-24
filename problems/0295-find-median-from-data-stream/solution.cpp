class MedianFinder {
private:
    priority_queue<int> l;
    priority_queue<int, vector<int>, greater<int>> r;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (l.empty()) {
            l.push(num);
            return;
        }
        if (l.size() == r.size()) {
            if (num > r.top()) {
                l.push(r.top());
                r.pop();
                r.push(num);
            } else {
                l.push(num);
            }
        } else {
            if (num < l.top()) {
                r.push(l.top());
                l.pop();
                l.push(num);
            } else {
                r.push(num);
            }
        }
    }
    
    double findMedian() {
        if (r.size() != l.size()) {
            if (r.size() > l.size()) {
                return r.top();
            } else {
                return l.top();
            }
        } else {
            return l.top() + (r.top() - l.top()) / 2.0;
        }
    }
};
