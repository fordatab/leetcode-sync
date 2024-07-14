class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> c(jewels.begin(), jewels.end());
        int g = 0;
        for (char a : stones) {
            if (c.find(a) != c.end()) {
                g++;
            }
        }
        return g;
    }
};