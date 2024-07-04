class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int x = 0;
        string out;
        while (x < word1.size() && x < word2.size()) {
            out += word1[x];
            out += word2[x];
            x++;
        }
        out += word1.substr(x, word1.size()-x);
        out += word2.substr(x, word2.size()-x);
        return out;

    }
};