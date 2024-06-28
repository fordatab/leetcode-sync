class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else {
                if (!stack.empty()) {
                    if (stack.top() == c -2 || stack.top() == c -1) {
                    stack.pop();
                } else {
                    return false;
                }
                } else {
                    return false;
                }
                
            }
        }
        return stack.empty();
    }
};
