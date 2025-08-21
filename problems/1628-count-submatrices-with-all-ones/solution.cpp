#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int R = mat.size();
        int C = mat[0].size();

        // width[i][j] = number of consecutive 1's ending at mat[i][j] in the row
        vector<vector<int>> width(R, vector<int>(C, 0));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (mat[i][j] == 1) {
                    width[i][j] = (j == 0 ? 1 : width[i][j-1] + 1);
                }
            }
        }

        int ans = 0;
        // For each cell (i, j), go upward and count rectangles
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (mat[i][j] == 0) continue;
                int minW = INT_MAX;
                for (int k = i; k >= 0; k--) {
                    if (width[k][j] == 0) break; // no more rectangles upward
                    minW = min(minW, width[k][j]);
                    ans += minW; // rectangles ending at (i, j) with top at row k
                }
            }
        }

        return ans;
    }
};
