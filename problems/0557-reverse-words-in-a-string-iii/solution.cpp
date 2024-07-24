class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        size_t f = 0;
        string out;
        string a;
        while ((f = s.find(" ", i)) != string::npos) {
            a = s.substr(i, f-i);
            reverse(begin(a), end(a));
            out += a + " ";
            i = f + 1;
        }
        a = s.substr(i, s.size() - i);
        reverse(begin(a), end(a));
        out += a;
        return out;
    }
};