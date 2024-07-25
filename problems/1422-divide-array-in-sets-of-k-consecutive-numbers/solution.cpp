class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> m;
        for (int a : nums) {
            m[a]++;
        }
        while (!m.empty()) {
            int top = begin(m)->first;
            for (int x = top; x < top + k; x++) {
                auto it = m.find(x);
                if (it == m.end()) {
                    return false;
                }
                it->second--;
                if (it->second == 0) {
                    m.erase(it);
                }
            }
        }
        return true;
    }
};