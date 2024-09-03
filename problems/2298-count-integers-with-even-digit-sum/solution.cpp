class Solution {
public:
    int countEven(int num) {
        int out = 0;
        for (int x = 1; x < num + 1; x++) {
            int n = x;
            int a = 0;
            while (n) {
                a += n % 10;
                n /= 10;
            }
            out += (a % 2 == 0);
        }
        return out;
    }
};