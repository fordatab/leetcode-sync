class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int s;
public:
    KthLargest(int k, vector<int>& nums) {
        s = k;
        priority_queue<int, vector<int>, greater<int>> p(nums.begin(), nums.end());
        while (p.size() > s) {
            p.pop();
        }
        pq = p;
    }
    
    int add(int val) {
                pq.push(val);

        if (pq.size() > s) {
                    pq.pop();

        }
        int out = pq.top();
        return out;
    }
};
