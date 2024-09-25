class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> m(128);
        for (int x = 0; x < s.size(); x++) {
            m[s[x]]++;
            m[t[x]]--;
        }
        int out = 0;
        for (int x = 0; x < 128; x++ ) {
            if (m[x] < 0) {
                out += -m[x];
            }
        }
        return out;

    }
};