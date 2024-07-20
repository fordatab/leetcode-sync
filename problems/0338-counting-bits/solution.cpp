class Solution {
public:
    int bits(int n) {
        int count = 0;
        while (n) {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> out(n+1);
        for (int x = 0; x < n + 1; x++) {
            out[x] = bits(x);
        }
        return out;
    }
};