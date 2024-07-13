class Solution {
public:
    int maxDepth(string s) {
        stack<char> stack;
        int maxDepth = 0;
        
        for (char c : s) {
            if (c == '(') {
                stack.push(c);
                maxDepth = max(maxDepth, (int)stack.size());
            } else if (c == ')') {
                if (stack.empty()) {
                    return -1;  // Invalid input: more closing than opening parentheses
                }
                stack.pop();
            }
        }
        
        if (!stack.empty()) {
            return -1;  // Invalid input: more opening than closing parentheses
        }
        
        return maxDepth;
    }
};