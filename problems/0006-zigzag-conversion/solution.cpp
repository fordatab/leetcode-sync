class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> v(numRows);

        int j = 0;
        int dir = -1;
        for (char c : s) {
            if (j == numRows -1 || j == 0) {
                dir = -dir;
            }
            v[j] += c;
            if (dir == 1) {
                j++;
            } else {
                j--;
            }
        }
        string out;
        for (string str : v) {
            out += str;
        }
        return out;
    }
};