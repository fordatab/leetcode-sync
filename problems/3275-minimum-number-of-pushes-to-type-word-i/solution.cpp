class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for (auto c : word) {
            freq[c-'a']++;
        }
        sort(rbegin(freq), rend(freq));
        int out = 0;
        for (int x = 0; x < 26; x++) {
            out += freq[x] * (x/8 + 1);
        }
        return out;
    }
};