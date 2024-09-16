class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> m;
        for (char c : p) {
            m[c]++;
        }
        vector<int> out;
        int l = 0; 
        unordered_map<char, int> window;
        for (int x = 0; x < s.size(); x++) {
            window[s[x]]++;
            if (x - l + 1 == p.size()) {
                // cout << l << endl;
                for (auto [a, b] : window) {
                    // cout << a << " " << b << endl;
                }
                if (window == m) {
                    out.push_back(l);
                }
                if (window[s[l]]-- == 1) {
                    window.erase(s[l]);
                } 
                l++;
            }
        }
        return out;
    }
};