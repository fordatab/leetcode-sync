class Solution {
public:
    int countBinarySubstrings(string s) {
        int m = 1;
        int n = s.size();
        int out = 0;
        while (m < n) {
            int l = 0;
            if (s[m] != s[m-1]) {
                cout << m << endl; 
                while (m-1-l >= 0 and m + l < n and s[m-1] == s[m-1-l] and s[m] == s[m+l]) {
                    l++;
                    out++;
                }
                cout << l << endl;
            }
            // m += l;
            m++; 
        } 
        return out;
    }
};