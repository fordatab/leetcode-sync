class Solution {
public:
    int balancedStringSplit(string s) {
        int out = 0;
        int x = 0;
        for (auto c : s) {
            if (c == 'R') {
                x++;
            } else {
                x--;
            }
            out += !x;
        }
        return out;
    }
};