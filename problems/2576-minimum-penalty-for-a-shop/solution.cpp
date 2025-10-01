class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pen(n);
        vector<int> closed(n+1);
        // closed[n] = -1;
        for (int x = n-1; x >= 0; x--) {
            if (customers[x] == 'Y') {
                closed[x] = closed[x+1] + 1;
            } else {
                closed[x] = closed[x+1];
            }
        }
        int empty = 0;
        int out = INT_MAX;
        int i = 0;
        int a = -1;
        for (int x : closed) {
            cout << x << " ";
        }
        cout << endl;
        int j = 0;
        for (int x = 0; x <= n; x++) {
            if (x > 0) {
                if (customers[x-1] == 'N') {
                    j++;
                }
            }
            closed[x] += j;
            cout << closed[x] << " "; 
        }
        auto it = min_element(closed.begin(), closed.end());
        return distance(closed.begin(), it); 
    }
};