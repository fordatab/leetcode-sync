class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> stk;
        string cur;
        int n = 0;
        for (char c : s) {
            if (isdigit(c)) {
                n = 10 * n + (c - '0'); // Fixed: Convert char to int correctly
            } else if (c == '[') {
                stk.push({cur, n});
                cur = "";
                n = 0;
            } else if (c == ']') {
                auto [prevStr, ct] = stk.top();
                stk.pop();
                string temp = cur;
                for (int x = 0; x < ct; x++) {
                    prevStr += temp;
                }
                cur = prevStr; // Fixed: Update cur with the decoded string
            } else {
                cur += c;
            }
        }
        return cur;
    }
};