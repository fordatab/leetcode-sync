class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int l = s.size()/2;
        int r = s.size()/2;
        if (s.size()%2 == 0) {
            l--;
        }
        while (l > -1) {
            if (s[l] != s[r]) {
                if (s[l] < s[r]) {
                    s[r] = s[l];
                } else {
                    s[l] = s[r];
                }
            }
            l--;
            r++;
        }
        return s;
    }
};