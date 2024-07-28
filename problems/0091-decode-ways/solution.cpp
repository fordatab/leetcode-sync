// Memoization solution
class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int, int> dp;
        dp[s.size()] = 1;
        return dfs(s, 0, dp);
    }

private:
    int dfs(string s, int i, unordered_map<int, int>& dp) {
        if (dp.count(i)) {
            return dp[i];
        }
        if (s[i] == '0') {
            return 0;
        }

        int res = dfs(s, i + 1, dp);
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
            res += dfs(s, i + 2, dp);
        }
        dp[i] = res;
        return res;
    }
};

// Dynamic Programming solution
// class Solution {
// public:
//     int numDecodings(string s) {
//         vector<int> dp(s.size() + 1);
//         dp[s.size()] = 1;
//         for (int i = s.size() - 1; i >= 0; i--) {
//             if (s[i] == '0') {
//                 dp[i] = 0;
//             } else {
//                 dp[i] = dp[i + 1];
//                 if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i + 1] <= '6')) {
//                     dp[i] += dp[i + 2];
//                 }
//             }
//         }
//         return dp[0];
//     }
// };
