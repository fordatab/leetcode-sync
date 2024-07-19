class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int x = 2; x < n-1; x++) {
            if (!n%x) {
                return true;
            }
        }
        return false;
    }
};