class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> a(128, 0);
        vector<int> b(128, 0);
        for (char c : t) {
            a[c]++;
        }
        int count = 0;
        for (int c : a) {
            if (c > 0) {
                count++;
            }
        }

        int have = 0;
        int l = 0;
        int m = INT_MAX;
        int start = 0;
        for (int r = 0; r < s.size(); r++) {
            b[s[r]]++;
            if (b[s[r]] == a[s[r]]) {
                have++;
            }

            while (have == count) {
                if (r - l + 1 < m) {
                    start = l;
                    m = r - l + 1;
                }
                b[s[l]]--;
                if (a[s[l]] > 0 && b[s[l]] < a[s[l]]) {
                    have--;
                }
                l++;                
            }
        }
        return m == INT_MAX ? "" : s.substr(start, m);
    }
};
