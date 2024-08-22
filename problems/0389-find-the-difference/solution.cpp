class Solution {
public:
    char findTheDifference(string s, string t) {
        char out = 0;
        for (const auto & c : s) {
            out ^= c;
        }
        for (const auto & c  : t) {
            out ^= c;
        }
        return out;
    }
};