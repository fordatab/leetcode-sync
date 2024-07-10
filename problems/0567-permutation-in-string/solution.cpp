class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int chars[26] = {};
        int c[26] = {};
        for (char ch : s1) {
            c[ch - 'a']++;
        }

        for (int r = 0; r < s2.size(); r++) {
            chars[s2[r]-'a']++;
            if (r - l + 1 > s1.size()) {
                chars[s2[l]-'a']--;
                l++;
            }
            bool t = true;
            for (int x = 0; x < 26; x++) {
                if (chars[x] != c[x]) {
                    t = false;
                }
            }
            if (t) {
                return true;
            }
        }
        return false;
    }
};
