class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int a : nums) {
            m[a]++;
        }
        int o = 0;
        for (auto a : m) {
            o += a.second*(a.second-1)/2;
        }
        return o;
    }
};