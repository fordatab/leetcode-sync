class Solution {
public:
    int lengthOfLastWord(string s) {
        bool space = true;
        int r = s.size();
        for (int x = s.size() - 1; x >= 0; x--) {
            if (s[x] != ' ' && space) {
                space = false;
                r = x;
            } 
            if (s[x] == ' ' && !space) {
                return r - x;
            }
        }
        cout << r << endl;
        return r + 1;
    }

};