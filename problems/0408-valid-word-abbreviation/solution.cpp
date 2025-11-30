class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int a = 0; // index into word
        int x = 0; // index into abbr

        while (x < (int)abbr.size()) {
            if (isdigit(abbr[x])) {
                // number part: cannot start with '0'
                if (abbr[x] == '0') {
                    return false;
                }
                int n = 0;
                while (x < (int)abbr.size() && isdigit(abbr[x])) {
                    n = n * 10 + (abbr[x] - '0');
                    x++;
                }
                a += n;
                // can't skip past the end of word
                if (a > (int)word.size()) {
                    return false;
                }
            } else {
                // need a character in word to match
                if (a >= (int)word.size() || word[a] != abbr[x]) {
                    return false;
                }
                a++;
                x++;
            }
        }

        // must have consumed the whole word
        return a == (int)word.size();
    }
};
