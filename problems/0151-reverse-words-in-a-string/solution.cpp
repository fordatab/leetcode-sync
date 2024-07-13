class Solution {
public:
    string reverseWords(string s) {
        bool start = false;
        string out = "";
        string tmp = "";
        for (int x = 0; x < s.size(); x++) {
            if (isalnum(s[x])) {
                start = true;
                tmp += s[x];
            } else {
                if (start) {
                    out = tmp + " " + out;
                    tmp = "";
                }
                start = false;
            }
        }
        if (isalnum(s[s.size()-1])) {
            out = tmp + " " + out;
        }
        return out.substr(0, out.size()-1);
    }
};