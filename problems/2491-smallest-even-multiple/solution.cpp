class Solution {
public:
    int smallestEvenMultiple(int n) {
        while (n % 2 == 1) {
            n+=n;
        }
        return n;
    }
};