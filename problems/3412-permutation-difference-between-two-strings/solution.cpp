class Solution {
public:
    int findPermutationDifference(string s, string t) {
        vector<int> b(26);
        for (int x = 0; x < s.size(); x++) {
            b[s[x]-'a'] = x; 
        }
        int a = 0;
        for (int x = 0; x < t.size(); x++) {
            a += abs(x - b[t[x]-'a']);
        }
        return a;
    }
};