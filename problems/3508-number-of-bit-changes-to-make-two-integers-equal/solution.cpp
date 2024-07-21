class Solution {
public:
    int minChanges(int n, int k) {
        if (n == k) {
            return 0;
        }
        if (k > n) {
            return -1;
        }
        int count = 0;
        for (int i = 0; i < 32; i++) {
            int a = (n >> i) & 1;
            int b = (k >> i) & 1;
            if (b && !a) {
                return -1;
            }
            if (a && !b) {
                count++;
            }
        }
        return count;

    }
};