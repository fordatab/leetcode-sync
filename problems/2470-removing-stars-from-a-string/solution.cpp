class Solution {
public:
    string removeStars(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == '*') {
                stack.pop();
            } else {
                stack.push(c);
            }
        }
        string out;
        while (!stack.empty()) {
            out += stack.top();
            stack.pop();
        }
        reverse(begin(out), end(out));
        return out;
    }
};