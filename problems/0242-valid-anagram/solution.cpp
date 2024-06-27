class Solution {
public:
    bool isAnagram(string s, string t) {
        int char_s[26] = {0};
        int char_t[26] = {0};

        for (auto a : s) {
            char_s[a-97]++;
        }
        for (auto a : t) {
            char_t[a-97]++;
        }

        for (int x = 0; x < 26; x++) {
            if (char_s[x] != char_t[x]) {
                return false;
            }
        }
        return true;


    }
};
