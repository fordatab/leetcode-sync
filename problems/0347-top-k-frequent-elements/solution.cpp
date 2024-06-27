class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for (auto a : nums) {
            m[a]++;
        }
        vector<pair<int, int>> v;
        for (auto a : m) {
            v.push_back({a.second, a.first});
        }
        make_heap(v.begin(), v.end());
        // priority_queue<pair<int, int>> pq;
        // // for (auto a : m) {
        // //     pq.push({a.second, a.first});
        // // }
        vector<int> out;
        for (const auto& p : v) {
            std::cout << "(" << p.first << ", " << p.second << ") ";
        }
        std::cout << std::endl;
        for (int x = 0; x < k; x++) {
            pop_heap(v.begin(), v.end());
            out.push_back(v.back().second);
            v.pop_back();
        }
        return out;
    }
};
