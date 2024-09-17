class Solution {
public:
    int longestSubstring(string s, int k) {
        unordered_map<char, int> m;
        int l = 0;
        for (auto c : s) {
            m[c]++;
        }
        int unique = m.size();
        int out = 0;

        for (int u = 1; u < unique + 1; u++) {
            int l = 0;
            int r = 0;
            m.clear();
            int unique = 0;
            int gt_k = 0;
            while (r < s.size()) {
                if (unique <= u) {
                    m[s[r]]++;
                    if (m[s[r]] == 1) {
                        unique++;
                    }
                    if (m[s[r]] == k) {
                        gt_k++; 
                    }
                    r++;
                } else {
                    m[s[l]]--;
                    if (m[s[l]] == 0) {
                        unique--;
                    }
                    if (m[s[l]] == k - 1) {
                        gt_k--;
                    } 
                    l++;
                }
                if (unique == u && gt_k == u) {
                    out = max(out, r - l);
                }
            }
        } 
        return out;
    }
};