class Solution {
public:
    int hIndex(vector<int>& c) {
        int n = c.size();
        vector<int> b(n + 1);
        for (int a : c) {
            if (a >= n) {
                b[n]++;
            } else {
                b[a]++;
            }
        } 
        int t = 0;
        for (int x = n; x > -1; x--) {
            t += b[x];
            if (t >= x) {
                return x;
            }
        }
        return 0;
    }
};