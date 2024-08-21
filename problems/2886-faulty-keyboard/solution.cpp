class Solution {
public:
    string finalString(string s) {
        string out;
        for (int x = 0; x < s.size(); x++) {
            if (s[x] == 'i') {
                reverse(begin(out), end(out));
            } else {
                out += s[x];
            }
        }
        return out;
    }
};