class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> used(26);
        for (char c : allowed) {
            used[c-'a'] = true;
        }
        int out = 0;
        for (string w : words) {
                    bool b = true;

            for (char c : w) {
                if (!used[c-'a']) {
                    b = false;
                }
            }
            out += b;
        }
        return out;
    }
};