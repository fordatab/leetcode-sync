class Solution {
private:
    int largestFactor(int n) {
        if (n <= 1) return 1;
        
        for (int i = n / 2; i >= 2; --i) {
            if (n % i == 0) {
                return i;
            }
        }
        
        return 1;  // If n is prime
    }
public:
    int minSteps(int n) {
        if (n == 2) {
            return 2;
        }
        vector<pair<int, int>> dp(n+1);
        // return -1;
        dp[0] = {0, 0}; //clip 0
        dp[1] = {0, 0};
        for (int x = 2; x < n+ 1; x++) {
            int f = largestFactor(x);
            cout << f << endl;
            if (dp[f].second == 0) {
                dp[x] = {x, 1};
            } else {
                dp[x].first = dp[f].first + 1 + (x/f)-1;
                dp[x].second = f;
            }

        }
        for (auto [a, b] : dp) {
            cout << a << " " << b << endl;
        }
        return dp[n].first;

    }
};