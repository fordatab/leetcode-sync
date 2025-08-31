class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        vector<int> Y(3);
        vector<int> others(3);
        int n = grid.size();
        // Y
        for (int x = 0; x < grid.size()/2; x++) {
            Y[grid[x][x]]++;
            // m[{x, x}]++;
            cout << x << " "<< x << endl;
        }
        cout << endl;
        for (int x = 0; x < grid.size()/2; x++) {
            Y[grid[x][n-x-1]]++;
            // m[{x, n-x-1}]++;
                        cout << x << " "<< n-x-1 << endl;

        }
         cout << endl;
        for (int x = 0; x < grid.size()/2+1; x++) {
            Y[grid[x+n/2][n/2]]++;
            // m[{x+n/2, n/2}]++;
                        cout << x + n/2<< " "<< n/2 << endl;

        }
        for (int a : Y) {
            cout << a << " ";
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                    others[grid[x][y]]++;
                
            }
        }
        for (int x = 0; x < 3; x++) {
            others[x] -= Y[x];
        }
        int Y_ct = n + n/2;
        int rest_ct = n*n - Y_ct;
        int best = INT_MAX;
        for (int x = 0; x < 3; x++) {
            int t = Y_ct - Y[x];
            for (int y = 0; y < 3; y++) {
                if (x != y) {
                    best = min(best, t + rest_ct - others[y]);
                }
            } 
        }
        
        return best;
    }
};