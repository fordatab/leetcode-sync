class Solution {
public:
    int partitionString(string s) {
        int out = 0;
        unordered_set<char> set;
        for (char c : s) {
            if (!set.insert(c).second) {
                out++;
                set.clear();
                set.insert(c);
            }
        }
        return out + 1;
    }
};