class Solution {
public:
    int numSub(string s) {
        int MOD = 1e9 + 7;
        int l = 0;
        int r = 0;
        int n = s.size(); 
        int out = 0; 
        while (r < n) {
            while (r < n and s[r] == '1') {
                r++;
            }
            if (s[l] == '1') {
                int length = r - l;
                long long ct = (long long) length * (length + 1) / 2;
                ct %= MOD;  
                // cout << r << " " << l << " " << " " << ct << endl;
                out += ct;
                out %= MOD;
            }
            r++;
            l = r;
        }

        return out;

    }
};