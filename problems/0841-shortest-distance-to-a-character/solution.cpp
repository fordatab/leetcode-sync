class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> out(s.size(), INT_MAX);
        for (int x = 0; x < s.size(); x++) {
            if (s[x] == c) {
                out[x] = 0;
            }
        }
        int prev = -1;
        for (int x = 0; x < s.size(); x++) {
            if (out[x] == 0) {
                prev = x;
            }
            if (prev != -1) {
                out[x] = x - prev;
            }
        }
        prev = s.size();
        for (int x = s.size()-1; x >= 0; x--) {
            if (out[x] == 0) {
                prev = x;
            }
            if (prev != s.size()) {
                out[x] = min(prev - x, out[x]);
            }
        }
        return out;
    }
};