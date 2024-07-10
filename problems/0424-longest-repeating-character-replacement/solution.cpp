class Solution {
public:
    int characterReplacement(string s, int k) {
        int chars[26] = {};
        int l = 0;
        int m = 0;
        for (int r = 0; r < s.size(); r++) {
            chars[s[r] - 'A']++;
            while (r - l - *max_element(chars, chars+26) + 1 > k) {
                chars[s[l] - 'A']--;
                l++;
            }
            m = max(m, r - l + 1);
        }
        return m;
    }
};
