class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0;
        int zero = 0;
        for (char c : s) {
            if (c == '1') {
                one++;
            } else {
                zero++;
            }
        }
        string str;
        while (one-- > 1) {
            str += '1';
        }
        while (zero--) {
            str += '0';
        }
        str += '1';
        return str;
    }
};