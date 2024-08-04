class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int out = 0;
        int g = x;
        while(g) {
            out += g%10;
            g/=10;
        }
        if (x%out) {
            return -1;
        } else {
            return out;
        }
    }
};