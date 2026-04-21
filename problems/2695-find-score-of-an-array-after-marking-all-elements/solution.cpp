class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        for (int i = 0; i < nums.size(); i++) {
            q.push({nums[i], i});
        }
        unordered_set<int> marked;
        long long out = 0;
        while (marked.size() < nums.size()) {
            auto [a, b] = q.top(); q.pop();
            if (marked.find(b) != marked.end()) {
                continue;
            }
            out += a;
            if (b > 0) {
                marked.insert(b - 1);
            }
            if (b < nums.size() - 1) {
                marked.insert(b + 1);
            }
            marked.insert(b);
        }
        return out;
    }
};