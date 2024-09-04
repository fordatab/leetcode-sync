class Solution {
public:
    bool checkString(string s) {
        bool has_b = false;
        for (char & c: s) {
            if (c == 'a' && has_b) {
                return false;
            } else if (c == 'b') {
                has_b = true;
            }
        }
        return true;
    }
};