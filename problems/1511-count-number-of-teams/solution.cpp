class Solution {
public:
    int numTeams(vector<int>& rating) {
        int out = 0;
        for (int x = 1; x < rating.size() - 1; x++) {
            int mid = rating[x];
            int lt = 0;
            int gt = 0;
            cout << x << endl;
            for (int l = 0; l < x; l++) {
                if (rating[l] < mid) {
                    // cout << l << endl;
                    lt++;
                }
            }
            for (int r = x + 1; r < rating.size(); r++) {
                if (rating[r] > mid) {
                    // cout << r << endl;
                    gt++;
                }
            }
            cout << lt << " " << gt << endl;
            out += lt * gt;
            int a = x - lt;
            int b = rating.size() - x - gt - 1;
            cout << a << " " << b << endl;
            out += a * b;
        }
        return out;
    }
};