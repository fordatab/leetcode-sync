class Solution {
public:
    int myAtoi(string s) {
        int i = 0;

        while (s[i] == ' ') {
            i++;
        }
        bool neg = false;
        if (s[i] == '-') {
            i++;
            neg = true;
        } else if (s[i] == '+') {
            i++;
        }
        int out = 0;

        while (s[i] >= '0' && s[i] <= '9') {
            if (out > INT_MAX/10 || (out == INT_MAX/10 && s[i] > 7 + '0')) {
                return neg ? INT_MIN : INT_MAX;
            }
            out *= 10;
            out += s[i++] - '0';

        }
        return neg ? -out : out;
    }
};