class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> m;
        for (int a : hand) {
            m[a]++;
        }
        while (!m.empty()) {
            int top = begin(m)->first;
            for (int x = top; x < top + groupSize; x++) {
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
