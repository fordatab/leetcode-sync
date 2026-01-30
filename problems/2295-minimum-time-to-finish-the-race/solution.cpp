class Solution {
public:
    int minimumFinishTime(vector<vector<int>>& tires, int changeTime, int numLaps) {
        vector<int> best(numLaps + 1, INT_MAX);
        int base = INT_MAX;
        for (auto t : tires) {
            base = min(base, t[0]);
        }
        for (auto t : tires) {
            int sum = 0;
            int time = t[0];
            int increase = t[1];
            for (int j = 1; j <= numLaps; j++) {
            // next time > changTime
                sum += time;
                best[j] = min(best[j], sum);
                if (time > INT_MAX / increase) break;

                time *= increase;
                if (time > base + changeTime) {
                    break;
                }

            } 
            
        }
        vector<int> dp(numLaps + 1, INT_MAX);
        dp[0] = 0;
        for (int x = 1; x <= numLaps; x++) {
            for (int j = 1; j <= x; j++) {
                if (best[j] == INT_MAX) {
                    continue;
                }
                dp[x] = min(dp[x], dp[x - j] + best[j] + (x == j ? 0 : changeTime));
            }

        }
        return dp[numLaps];
    }
};