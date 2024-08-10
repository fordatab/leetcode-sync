class Solution {
public:
    int minFlips(int a, int b, int c) {
        int out = 0;
        for (int x = 0; x < 32; x++) {
            int f = a % 2;
            int s = b % 2;
            int t = c % 2;
            
            if (t == 0) {
                out += f + s;  // If t is 0, we need to flip all 1s in f and s
            } else {  // t == 1
                if (f == 0 && s == 0) {
                    out += 1;  // If t is 1 and both f and s are 0, we need one flip
                }
            }
            
            a /= 2;
            b /= 2;
            c /= 2;
        }
        return out;
    }
};