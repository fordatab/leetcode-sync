class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int sum = (rolls.size() + n) * mean;
        for (int& x : rolls) {
            sum -= x;
        } 
        cout << sum << " " << mean << " " << n << endl;
        if (sum < n || (sum > 6 *n)) {
            return {};
        } 
         cout << "A " << endl;
        vector<int> out(n);
        int x = 0;
        while (sum--) {
            out[x%n]++; 
            x++;
        }
        return out;
    }
};