class Solution {
public:
    int numberOfSteps(int num) {
        int out = 0;
        while (num) {
            if (num%2 == 0) {
                num >>= 1;
            } else {
                num &= 0b11111111111111111111111111111110;
            }
            out++;
        }
        return out;
    }
};