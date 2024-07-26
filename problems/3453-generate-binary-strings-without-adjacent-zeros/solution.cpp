class Solution {
public:
    vector<string> validStrings(int n) {
        vector<string> out;
        string s = "";
        dfs(out, n, s);
        return out;
    }

    void dfs(vector<string>& out, int n, string& s) {
        if (n == 0) {
            out.push_back(s);
            return;
        }
        if (s.empty()) {
            s.push_back('0');
            dfs(out, n - 1, s);
            s.pop_back();
            s.push_back('1');
            dfs(out, n - 1, s);
            s.pop_back();
            return;
        }


        if (s.back() == '1') {
            cout << n << endl;
            s.push_back('0');
            dfs(out, n - 1, s);
            s.pop_back();
        }
        s.push_back('1');
        dfs(out, n - 1, s);
        s.pop_back();
    }
};