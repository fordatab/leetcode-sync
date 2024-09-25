class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int a : nums) {
            m[a]++;
        }
        auto maxPair = std::max_element(
        m.begin(), m.end(),
        [](const auto& a, const auto& b) {
            return a.second < b.second; // Compare based on the value (second)
        }
        );
        int out = 0;
        for (auto [a,b] : m) {
            if (b == maxPair->second) {
                out += b;
            }
        }
        return out;
    }
};