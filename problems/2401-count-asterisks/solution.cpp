class Solution {
public:
    int countAsterisks(string s) {
        int out = 0;
        bool pair = false;
        for (char c : s) {
            if (c == '|' && !pair) {
                pair = true;
            } else if (c == '|' && pair) {
                pair = false;
            }
            if (c == '*' && !pair) {
                out++;
            }
        }
        return out;
    }
};