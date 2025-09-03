class Solution {
public:
    int dp[100][100][100]; // constraints: n <= 100

    int solve(vector<int>& boxes, int l, int r, int k) {
        if (l > r) return 0;
        if (dp[l][r][k] != -1) return dp[l][r][k];

        // compress duplicates at the end
        int origR = r, origK = k;
        while (r > l && boxes[r] == boxes[r-1]) {
            r--;
            k++;
        }

        int res = solve(boxes, l, r-1, 0) + (k+1)*(k+1);

        for (int i = l; i < r; i++) {
            if (boxes[i] == boxes[r]) {
                res = max(res, solve(boxes, l, i, k+1) + solve(boxes, i+1, r-1, 0));
            }
        }

        return dp[l][origR][origK] = res;
    }

    int removeBoxes(vector<int>& boxes) {
        memset(dp, -1, sizeof(dp));
        return solve(boxes, 0, boxes.size()-1, 0);
    }
};
