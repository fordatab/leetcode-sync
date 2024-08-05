class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> m;
        unordered_map<string, int> m1;
        for (string a : words1) {
            m[a]++;
        }
        for (string b : words2) {
            m1[b]++;
        }
        int out = 0;
        for (string c : words1) {
            if (m[c] == 1 && m1[c] == 1) {
                out ++;
            }
        }
        return out;
    }
};