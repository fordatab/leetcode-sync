class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int m = strs.size();
        int n = strs[0].size();
        int out = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 1; y < m; y++) {
                if (strs[y][x] < strs[y-1][x]) {
                    out++;
                    break;
                }
            }
        }
        return out;
    }
};