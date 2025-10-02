class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double out = 0.0;
        int i = 0;
        int prev = 0;
        while (income > 0) {
            int a = min(income, brackets[i][0] - prev);
            // cout << a << endl;
            out += a * brackets[i][1] / 100.0;
            prev = brackets[i][0];
            income -= a;
            i++;
            cout << out << endl;
        }
        return out;
    }
};