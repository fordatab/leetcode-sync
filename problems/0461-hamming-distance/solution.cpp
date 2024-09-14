class Solution {
public:
    int hammingDistance(int x, int y) {
        int out = 0;
        for (int i = 0; i < 32; i++) {
            int a = (x >> i) & 1;
            int b = (y >> i) & 1;
            out += (a ^ b);
        }
        return out;
    }
};