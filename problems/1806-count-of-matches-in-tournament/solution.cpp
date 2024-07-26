class Solution {
public:
    int numberOfMatches(int n) {
        int x = 0;
        while (n != 1) {
            if (n%2) {
                x += n/2 + 1;
            } else {
                x += n/2;
            }
            n /= 2;
        }
        return x;
    }
};