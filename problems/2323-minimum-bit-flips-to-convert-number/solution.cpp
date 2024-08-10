class Solution {
public:
    int minBitFlips(int start, int goal) {
        int out = 0;
        for (int x = 0; x < 32; x++) {
            int a = (start >> x) & 1;
            int b = (goal >> x) & 1;
            if (a != b) {
                out++;
            }
        }
        return out;
    }
};