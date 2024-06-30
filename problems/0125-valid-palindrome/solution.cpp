class Solution {
public:
    bool isPalindrome(string s) {
        int a = 0;
        int b = s.size()-1;
        while (a - b < 1 && a != b) {
            while (!isalnum(s[a])) {
                if (a == s.size()-1) {
                    return true;
                }
                a++;
            }
            while (!isalnum(s[b])) {
                if (b == 0) {
                    return true;
                }
                b--;
            }

            if (tolower(s[a]) == tolower(s[b])) {
                a++;
                b--;
            } else {
                return false;
            }
        }
        return true;
    }
};
