class Solution {
public:
    int scoreOfString(string s) {
        int t = 0;
        for (int x = 0; x < s.size() - 1; x ++) {
            t += abs(s[x]-s[x+1]);
        }
        return t;
    }
};