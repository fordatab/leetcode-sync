class Solution {
private:
    static bool customComparator(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;  // Tie-breaker: second element in descending order
        }
        return a.first < b.first;  // Primary sort: first element in ascending order
    }
public:
    vector<int> frequencySort(vector<int>& nums) {
        vector<pair<int,int>> p;
        unordered_map<int,int> m;
        for (int x : nums) {
            m[x]++;
        }
        for (auto [a, b] : m) {
            p.push_back({b, a});
        }
        sort(begin(p), end(p), customComparator);
        vector<int> out;
        for (auto g : p) {
            for (int x = 0; x < g.first; x++) {
                out.push_back(g.second);
            }
        }
        return out;
    }
};