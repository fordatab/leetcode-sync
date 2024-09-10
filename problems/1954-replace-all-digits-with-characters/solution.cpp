class Solution {
public:
    string replaceDigits(string s) {
        char prev = ' ';
        for (char & c : s) {
            if (isdigit(c)) {
                c = prev + c - '0';
            }
            prev = c;
        }
        return s;
    }
};