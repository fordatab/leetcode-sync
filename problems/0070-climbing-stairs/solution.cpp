class Solution {
public:
    int climbStairs(int n) {
        vector<int> c(n+1);
        c[0] = 1;
        c[1] = 2;
        for (int x = 2; x < n; x++) {
            c[x] = c[x-1] + c[x-2];
        }
        return c[n-1];
    }
};
