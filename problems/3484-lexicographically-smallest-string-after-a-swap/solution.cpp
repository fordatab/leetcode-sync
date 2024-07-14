class Solution {
public:
    string getSmallestString(string s) {
        for (int x = 0; x < s.size()-1; x++) {
            int a = (int)s[x];
            int b = (int)s[x+1];
            if (a %2 == b%2) {
                if (b < a) {
                    swap(s[x], s[x+1]);
                    break;
                }
            }
        }
        return s;
    }
};