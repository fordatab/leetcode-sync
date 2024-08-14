class Solution {
public:
    bool halvesAreAlike(string s) {
        int l = s.size()/2-1;
        int r = s.size()/2;
        for (char& c : s) c |= 0b00100000;
        int v = 0;
        while (l > -1) {
            cout << s[l] << " " << s[r] << endl;
            if (s[l] == 'a' || s[l] == 'e' || s[l] == 'i' || s[l] == 'o' || s[l] == 'u') {
                v++;
            }
            if (s[r] == 'a' || s[r] == 'e' || s[r] == 'i' || s[r] == 'o' || s[r] == 'u') {
                v--;
            }
            l--;
            r++;
            cout << v << endl;
        }
        return !v;
    }
};