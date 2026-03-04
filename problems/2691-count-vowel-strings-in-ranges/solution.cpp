class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') {
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> out;
        int n = words.size();
        vector<int> prefix(n + 1);
        // prefix[0] = isVowel(words[0][0]) and isVowel(words[0].back());
        for (int i = 1; i <= n; i++) {
            prefix[i] = (isVowel(words[i-1][0]) and isVowel(words[i-1].back())) + prefix[i-1];
        }
        // for (int p : prefix) {
        //     cout << p << " ";
        // }
        cout << endl;
        for (auto q : queries) {
            int r = prefix[q[1] + 1];
            int l = prefix[q[0]];
            out.push_back(r - l);
        }
        return out;

    }
};