class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.size();
        vector<int> a(n);
        vector<int> b(n);
        int c = 0;
        for (int x = 0; x < n; x++) {
           b[x] = c;
           c += (s[x] == 'b');
            
        }
        c = 0;
        for (int x = n-1; x >= 0; x--) {
           a[x] = c;
           c += (s[x] == 'a');
        }

        int out = n;
        for (int x = 0; x < n; x++) {
            out = min(out, a[x] + b[x]);
        }

        return out;

    }
};


