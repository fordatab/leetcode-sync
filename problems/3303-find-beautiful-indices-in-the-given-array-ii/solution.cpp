class Solution {
public:
    // Helper function to build the Longest Prefix Suffix (LPS) array
    vector<int> getLPS(const string& p) {
        int m = p.length();
        vector<int> lps(m, 0);
        int len = 0;
        for (int i = 1; i < m; ) {
            if (p[i] == p[len]) {
                lps[i++] = ++len;
            } else {
                if (len != 0) len = lps[len - 1];
                else lps[i++] = 0;
            }
        }
        return lps;
    }

    // Helper function to find all occurrences of pattern p in string s
    vector<int> kmp(const string& s, const string& p) {
        vector<int> res;
        if (p.empty()) return res;
        vector<int> lps = getLPS(p);
        int n = s.length(), m = p.length();
        for (int i = 0, j = 0; i < n; ) {
            if (s[i] == p[j]) {
                i++; j++;
                if (j == m) {
                    res.push_back(i - j);
                    j = lps[j - 1];
                }
            } else {
                if (j != 0) j = lps[j - 1];
                else i++;
            }
        }
        return res;
    }

    vector<int> beautifulIndices(string s, string a, string b, int k) {
        vector<int> indices_a = kmp(s, a);
        vector<int> indices_b = kmp(s, b);
        vector<int> ans;

        for (int pos_a : indices_a) {
            // Find the first occurrence of b that is >= pos_a - k
            auto it = lower_bound(indices_b.begin(), indices_b.end(), pos_a - k);
            
            // Check if this occurrence also satisfies the condition <= pos_a + k
            if (it != indices_b.end() && *it <= pos_a + k) {
                ans.push_back(pos_a);
            }
        }
        return ans;
    }
};