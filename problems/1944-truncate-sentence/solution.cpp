class Solution {
public:
    string truncateSentence(string s, int k) {
        int t = 0;
        for (int x = 0; x < s.size(); x++) {
            t += (s[x] == ' ');
            if (t == k) {
                return string(begin(s), begin(s) + x);
            }
        }
        return s;
    }
};