class Solution {

struct CompareDistance {
    bool operator()(const std::pair<double, int>& a, const std::pair<double, int>& b) {
        return a.first < b.first;  // Compare based on the first element (distance)
    }
};
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, int>, vector<pair<double, int>>, CompareDistance> pq;
        for (int x = 0; x < points.size(); x++) {
            vector<int> a = points[x];
            double distance = sqrt(a[0] * a[0] + a[1]* a[1]);
            pq.push({distance, x});
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<vector<int>> out;
        while (pq.size()) {
            auto a = pq.top();
            out.push_back(points[a.second]);
            pq.pop();
        }
        return out;
    }
};
