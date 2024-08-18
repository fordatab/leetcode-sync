class Solution {
public:
    int hammingWeight(int n) {
        int out = 0;
        for (int x = 0; x < 32; x++) {
            out += (n >> x) & 1;
        }
        return out;
    }
};