class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream str(s);
        string word;
        unordered_map<char, string> m;
        unordered_map<string, char> n;
        for (int x = 0; x < pattern.size(); x++) {
            if (!(str >> word)) {
                return false;
            }
            if ((m.find(pattern[x]) != m.end() && m[pattern[x]] != word) || (n.find(word) != n.end() && n[word] != pattern[x])) {
                return false;
            }
            m[pattern[x]] = word;
            n[word] = pattern[x];
        }
        if (str >> word) {
            return false;
        }
        return true;
    }
};