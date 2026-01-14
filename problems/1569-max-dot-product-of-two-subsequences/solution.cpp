class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        dp[m-1][n-1] = nums1[m-1] * nums2[n-1];  

        for (int x = m - 1; x >= 0; x--) {
            for (int y = n - 1; y >= 0; y--) {
                
                int curr = nums1[x] * nums2[y];
                int selected = 0;
                if (x != m - 1 and y != n - 1) {
                        selected = dp[x+1][y+1];

                    // make a new subsequence if selected is negative. it doesnt help the total
                    if (selected < 0) {
                        selected = 0; 
                    }
                }
                int down = INT_MIN;
                if (x != m - 1) {
                    down = dp[x+1][y];
                }
                int right = INT_MIN;
                if (y != n - 1) {
                    right = dp[x][y+1];
                }
                dp[x][y] = max({curr + selected, down, right});   
            }
        }

        return dp[0][0];
    }
};