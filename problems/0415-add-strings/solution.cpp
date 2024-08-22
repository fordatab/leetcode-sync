class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int c = 0;
        string out;
        while (i>=0 || j >=0) {
            int n = c;
            if (i>=0) {
                n += num1[i--] - '0';
            }
            if (j >=0 ) {
                n += num2[j--] - '0';
            }
            out += to_string(n%10);
            c = n/10;
        }
        if (c) {
            out += "1";
        }
        reverse(begin(out), end(out));
        return out;
    }
};