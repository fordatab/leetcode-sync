class Solution {
public:
    string reverseOnlyLetters(string s) {
        int l = 0;
        string out(s.size(), '\0');
        int r = s.size() - 1;
        while (r >= 0) {
            if (isalpha(s[r])) {
                if (isalpha(s[l])) {
                    out[l] = s[r];
                    l++;
                    r--;
                } else {
                    out[l] = s[l];
                    l++;
                }
            } else {
                out[r] = s[r];
                r--;
            }
        }
        return out;
    }
};