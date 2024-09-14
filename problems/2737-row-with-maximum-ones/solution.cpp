class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int row = 0;
        int t = 0; 
        int i = 0;
        for (auto v : mat) {
            int m = 0;
            for (int x : v) {
                if (x) {
                    m++;
                }
            }
            if (m > t) {
                t = m;
                row = i;
            }
            i++;
        }

        return {row, t};
    }
};