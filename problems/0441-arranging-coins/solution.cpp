class Solution {
public:
    int arrangeCoins(int n) {
        int out = 1;
        while (n > 0) {
            n -= out;
            out++;
        }
        // cout << n << endl;
        return n == 0 ? out - 1 : out - 2;
    }
};