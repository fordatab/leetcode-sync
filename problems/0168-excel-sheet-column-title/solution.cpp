class Solution {
public:
    string convertToTitle(int columnNumber) {
        string out;
        while (columnNumber) {
            columnNumber--;
            out += 'A' + (columnNumber % 26);
            columnNumber /= 26;
        }
        reverse(begin(out), end(out));
        return out;
    }
};