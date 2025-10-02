class Solution {
public:
    void bt(vector<string>& out, string& str, int i, string s) {
        if (i == s.size()) {
            out.push_back(str);
            return;
        }
        vector<char> choices;
        if (s[i] == '{') {
            i++;
            while (s[i] != '}') {
                if (s[i] == ',') {
                    i++;
                    continue;
                }
                choices.push_back(s[i]);
                i++;
            }
            i++;
            sort(choices.begin(), choices.end());
            for (char c : choices) {
                str.push_back(c);
                bt(out, str, i, s);
                str.pop_back();
            }
        } else {
            str.push_back(s[i]);
            bt(out, str, i + 1, s);
            str.pop_back();
        }

    }
    vector<string> expand(string s) {
        vector<string> out;
        string str;
        bt(out, str, 0, s);
        return out;
    }
};