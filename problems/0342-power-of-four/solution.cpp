class Solution {
public:
    bool isPowerOfFour(int n) {
        if (n < 1) {
            return false;
        }
        if ((n & (n - 1)) != 0) {  // Check if n is a power of 2
            return false;
        }
        return (n - 1) % 3 == 0;
    }
};