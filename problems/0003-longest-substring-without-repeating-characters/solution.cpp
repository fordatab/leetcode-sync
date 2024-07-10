class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int m = 0;
        unordered_set<char> set;
        while (r < s.size()) {
            if (set.find(s[r]) == set.end()) {
                set.insert(s[r]);
                m = max(m, static_cast<int>(set.size()));
            } else {
                while (s[l] != s[r]) {
                    set.erase(s[l]);
                    l++;
                }
                l++;
            }
            r++;
        }
        return m;
    }
};
