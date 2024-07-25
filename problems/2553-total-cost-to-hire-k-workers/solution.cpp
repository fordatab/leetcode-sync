class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        if (costs.size() == 1) {
            return costs[0];
        }
        priority_queue<int, vector<int>, greater<int>> lq;
        priority_queue<int, vector<int>, greater<int>> rq;
        unordered_set<int> s;
        int l = 0;
        candidates = min(candidates, (int)costs.size()/2);
        while (l < candidates) {
            lq.push(costs[l]);
            l++;
        }
        int r = costs.size() - 1;
        while (r >= costs.size() - candidates) {
            rq.push(costs[r]);
            r--;
        }

        cout << l << " " << r << endl;
        long long out = 0;
        for (int x = 0; x < k; x++) {
            cout << lq.top() << " " << rq.top() << endl;
            if (rq.empty() || (!lq.empty() && lq.top() <= rq.top())) {
                out += lq.top();
                cout << lq.top() << endl;;
                lq.pop();
                if (l<=r) {

                    lq.push(costs[l]);
                                        l++;
                } else {
                }
            } else {
                out += rq.top();

                                cout << rq.top() << endl;;

                rq.pop();
                if (l<=r) {
                    rq.push(costs[r]);
                                        r--;
                } else {
                }
            }
        }
        return out;
    }
};