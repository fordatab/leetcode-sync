class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        s1.push_back(' ');
        s2.push_back(' ');
        unordered_map<string, int> m;
        int a;
        int prev = 0;
        while ((a = s1.find(" ", prev)) != string::npos) {
            cout << a << " " << prev << endl;
            string s = s1.substr(prev, a-prev);
            prev = a + 1;
            m[s]++;
        }
        prev = 0;
        while ((a = s2.find(" ", prev)) != string::npos) {
            string s = s2.substr(prev, a-prev);
            prev = a + 1;
            m[s]++;
        }
        vector<string> out;
        for (auto [a, b] : m) {
            if (b == 1) {
                out.push_back(a);
            }
        }
        return out;
    }
};