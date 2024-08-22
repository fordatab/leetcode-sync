class Solution {
public:
    int titleToNumber(string s) {
        int out = 0;
        for (char c : s) {
            out*=26;
            // cout << c[x] - 64 << " " << out << endl;
            out += (c - 64);
            // cout << c[x] - 64 << " " << out << endl;

        }
        return out;
    }
};