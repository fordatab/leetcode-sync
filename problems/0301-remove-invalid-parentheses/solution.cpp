class Solution {
public:
    void bt(unordered_set<string>& out, string& cur, int lRemove, int rRemove, int i, int balance, string s) {
        if (lRemove == 0 and rRemove == 0 and i == s.size()) {
            out.insert(cur);
            return;
        }
        if (i == s.size()) {
            return;
        }
        // more closed than open currently
        if (balance < 0) {
            return;
        }
                if (lRemove < 0 || rRemove < 0) return;
        // not enough chars left to remove required ones
        if (lRemove + rRemove > (int)s.size() - i) return;


        if (s[i] == '(') {
                bt(out, cur, lRemove - 1, rRemove, i + 1, balance, s);
                cur.push_back('(');
                bt(out, cur, lRemove, rRemove, i + 1, balance + 1, s);
                cur.pop_back();
            
        } else if (s[i] == ')') {
                bt(out, cur, lRemove, rRemove - 1, i + 1, balance, s);
                cur.push_back(')');
                bt(out, cur, lRemove, rRemove, i + 1, balance - 1, s);
                cur.pop_back();
            
        } else { // character
            cur.push_back(s[i]);
            bt(out, cur, lRemove, rRemove, i + 1, balance, s);
            cur.pop_back();
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int lRemove = 0;
        int rRemove = 0;
        for (char c : s) {
            if (c == '(') {
                lRemove++;
            } else if (c == ')') {
                if (lRemove > 0) {
                    lRemove--;
                } else {
                    rRemove++;
                }
            }
        }
        int totalRemove = lRemove + rRemove;
        unordered_set<string> out;
        string cur;
        bt(out, cur, lRemove, rRemove, 0, 0, s);
        return vector<string> (out.begin(), out.end());
    }
};