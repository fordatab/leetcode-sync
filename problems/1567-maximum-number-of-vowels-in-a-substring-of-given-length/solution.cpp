class Solution {
public:
    bool isvowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int maxVowels(string s, int k) {
        int l = 0;
        int m = 0;
        int c = 0;
        for (int r = 0; r < s.size(); r++) {
            if (isvowel(s[r])) {
                c++;
            }
            if (r - l + 1 == k) {
                m = max(m, c);
                if (isvowel(s[l])) {
                    c--;
                }
                l++;
            }
        }
        return m;
    }
};