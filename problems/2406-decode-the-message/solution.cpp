class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> m(26, -1);
        int idx = 0;
        for (char c : key) {
            if (c != ' ' && m[c-'a'] == -1) {
                m[c-'a'] = idx++;
            }
        }

        for (char &c : message) {
            if (c >= 'a' && c <= 'z') {  // Only decode lowercase letters
                c = m[c-'a'] + 'a';
            }
        }
        return message;
    }
};
