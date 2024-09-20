class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (words.size() != s.size()) return false;
        int m = min(words.size(), s.size() ) ;
        for (int x = 0; x < m; x++ ) {
            if (words[x][0] != s[x]) {
                return false;
            }
        }
        return true;
    }
};