class Solution {
public:
    void bt(vector<string>& out, string& cur, int ct, string& s, int idx) {
        if (idx == s.size() && ct == 4) {
            out.push_back(cur);
            return;
        }
        if (idx == s.size() || ct > 4) return;

        for (int len = 1; len <= 3 && idx + len <= s.size(); len++) {
            string seg = s.substr(idx, len);
            if (seg.size() > 1 && seg[0] == '0') break;   // leading zero
            if (stoi(seg) > 255) break;                   // too big

            int before = cur.size();
            if (ct > 0) cur.push_back('.');
            cur += seg;

            bt(out, cur, ct + 1, s, idx + len);

            cur.resize(before); // backtrack
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> out;
        string cur;
        bt(out, cur, 0, s, 0);
        return out;
    }
};
