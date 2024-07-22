class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        bool b = true;
        int se = 0;
        while (b) {
            b = false;;
            for (int x = 0; x < s.size(); x++) {
                if (x < s.size() - 1 && s[x] == '0' && s[x+1] == '1') {
                    s[x] = '1';
                    s[x+1] = '0';
                    b = true;
                    x++;
                }
            }
            if (b) {
            se++;

            }
        }
        return se;
    }
};